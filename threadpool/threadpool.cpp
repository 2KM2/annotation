#include <errno.h>
#include <pthread.h>
#include <string.h>
#include <stdio.h>
#include <queue>
#include <malloc.h>
#include "list.h"
#include  "threadpool.h"

/**
 * @brief http://www.360doc.com/content/22/0519/17/99071_1032210703.shtml
 * 
 */
using namespace std;
typedef struct __threadpool
{
    /* data */
    struct list_head task_queue;//任务队列
    size_t nthreads;
    size_t stacksize;
    pthread_t tid;//线程id,整个线程池只有一个,平时运行的时候是空值,退出时候,他是用来实现链式等待的关键
    pthread_mutex_t mutex;
    pthread_cond_t  cond;
    pthread_key_t key; //用于区分这个线程是否是线程池创建的
    pthread_cond_t *terminate;//退出时的标记位,调用退出的那个要等待的condition
}threadpool;

//线程任务实体
typedef struct __threadpool_task_entry
{
    struct list_head list;
    struct threadpool_task  task;
}threadpool_task_entry;



static pthread_t __zero_tid;//ToDo：why define this
/**
 * @brief  __threadpool_terminate
 * 
 * @param in_pool 
 * @param pool 
 */
static void __threadpool_terminate(int in_pool, threadpool_t *pool)
{
        /**
     * @brief 
     * PTHREAD_COND_INITIALIZER 和 pthread_cond_init()都是初始化条件量
     * 
     * 两种方式创建有所区别，
     * 
     * 第一种是创建静态全局的，所创建的量在全局区，
     * 第二种创建的量在栈，两种的区别我们可以理解为全局变量和局部变量的差异，
     * 
     * 对于两种方式，
     * 
     * 如果创建的是全局的条件量则用第一种方式初始化，
     * 如果是在函数内部创建则用第二种方式。这里其实跟互斥锁一样，互斥锁也可以用这两种方式初始化，原理相同
     * 
     */
    pthread_cond_t term = PTHREAD_COND_INITIALIZER;//条件变量初始化
    pthread_mutex_lock(&pool->mutex);
	pool->terminate = &term;

    //广播所有等待的消费者
    pthread_cond_broadcast(&pool->cond);

    //每个由线程创建的线程都设置了一个key，
    if (in_pool)
	{
		/* Thread pool destroyed in a pool thread is legal. */
		pthread_detach(pthread_self());//
		pool->nthreads--;
	}

    //如果还有线程没有退完,我会等
    while (pool->nthreads > 0)
		pthread_cond_wait(&term, &pool->mutex);//terminate的等待

    pthread_mutex_unlock(&pool->mutex);

    //同样等待打算退出的上一个人
    if (memcmp(&pool->tid, &__zero_tid, sizeof (pthread_t)) != 0)
		pthread_join(pool->tid, NULL);
}

//线程运行的函数,消费者
static void *__threadpool_routine(void *args)
{
    printf("__threadpool_routine\n");

    threadpool_t *pool=(threadpool_t * )args;
    struct __threadpool_task_entry *entry;
    struct list_head **pos = &pool->task_queue.next;  // 第一个任务

	void (*task_routine)(void *);
	void *task_context;
	pthread_t tid;

    pthread_setspecific(pool->key, pool); // 此处把pool搞成thread_local了
    //每个线程内部都可以获取这个
    
    while (1)
    {
        pthread_mutex_lock(&pool->mutex);
		// 这个队列是线程池公共的队列，所以需要加锁

        // 此处是消费者行为，如果没停止，且任务队列没任务，就wait在这
        while(!pool->terminate&&list_empty(&pool->task_queue))
             pthread_cond_wait(&pool->cond, &pool->mutex);

        if (pool->terminate)  // 停止了就出去
			break;

     	// 我们取出第一个这个task
		entry = list_entry(*pos, struct __threadpool_task_entry, list);
		list_del(*pos); 
        
        //先解锁
        pthread_mutex_unlock(&pool->mutex);

   		task_routine = entry->task.routine;
		task_context = entry->task.context;
		free(entry);

		// 此处是执行
		task_routine(task_context);
        
        //如果task_routine就是销毁线程池
        //线程池里面的线程可以销毁线程池
        if (pool->nthreads == 0)
		{
			/* Thread pool was destroyed by the task. */
			free(pool);
			return NULL;
		}
    }
    /** 退出流程:
     *  拿出pool上的tid放到临时变量,且把自己的tid放上去
     * 1.第一个从pool上拿tid的发现值为0,可以直接结束。不用负责等待任何其他人,但我在完全结束之前需要有人负责等待我的结束
     * 所以我会把我的id放上去
     * 
     * 2.发现pool拿出来的不是0，说明我要负责join上一个人,并且把我的tid放上去,让下一个负责我
     * 
     * 3.发现pool->nthreads为0的人, 就可以通知terminate(本身就是pthread_cond_t)去通知发起destroy的人
     */
    tid = pool->tid;
    pool->tid = pthread_self(); 
    //最后一个人负责叫醒destroy
    if (--pool->nthreads == 0)
		pthread_cond_signal(pool->terminate);
    pthread_mutex_unlock(&pool->mutex);   // while(1) break;//没有释放锁


    //只有第一个人拿到了0值
    //
   	if (memcmp(&tid, &__zero_tid, sizeof (pthread_t)) != 0)
        //只要不是0值,我就负责等上一个结束才能退
        pthread_join(tid, NULL);

    return NULL;
}
/**
 * @brief  初始化lock相关，就是mutex，conditional_variable
 * @note   
 * @param  *pool: 
 * @retval 
 */
static int __thrdpool_init_locks(threadpool_t *pool)
{
	int ret;

	ret = pthread_mutex_init(&pool->mutex, NULL);
	if (ret == 0)
	{
		ret = pthread_cond_init(&pool->cond, NULL);
		if (ret == 0)
			return 0;

		pthread_mutex_destroy(&pool->mutex);
	}

	errno = ret;
	return -1;
}
/**
 * @brief 销毁lock相关，就是mutex，conditional_variable
 * 
 * @param pool 
 */
static void __threadpool_destroy_locks(threadpool_t *pool)
{
	pthread_mutex_destroy(&pool->mutex);
	pthread_cond_destroy(&pool->cond);
}

static int __thrdpool_create_threads(size_t nthreads, threadpool_t *pool)
{
    	pthread_attr_t attr;
	    pthread_t tid;
	    int ret;
        ret = pthread_attr_init(&attr);
        if(ret==0)
        {
            if (pool->stacksize)
			pthread_attr_setstacksize(&attr, pool->stacksize);
           	while (pool->nthreads < nthreads)
            {
                ret=pthread_create(&tid, &attr, __threadpool_routine, pool);
                if (ret == 0)
				pool->nthreads++;
			else
				break;
            }
            pthread_attr_destroy(&attr);
            if (pool->nthreads == nthreads)
			return 0;
            __threadpool_terminate(0, pool);
        }
    	errno = ret;
	    return -1;
}
threadpool_t *threadpool_create(size_t nthreads,size_t stacksize)
{
    threadpool_t  *pool;
    int ret;
    //分配
    pool=(threadpool_t *)malloc(sizeof(threadpool_t));//唯一的

    if(pool)
    {
	// 2. 初始化
		if (__thrdpool_init_locks(pool) >= 0)
		{
           ret = pthread_key_create(&pool->key, NULL);
            if (ret == 0)
			{
                INIT_LIST_HEAD(&pool->task_queue);
                pool->stacksize = stacksize;
                pool->nthreads = 0;
				memset(&pool->tid, 0, sizeof (pthread_t));
				pool->terminate = NULL;
                if(__thrdpool_create_threads(nthreads,pool)>=0)
                {
                    return pool;
                }
                pthread_key_delete(pool->key);
            }
            else
            {
                errno=ret;
            }

            __threadpool_destroy_locks(pool);

        }
        free(pool);
    }
    return NULL;
}

/**
 * @brief  这里的线程池调度，其实就是生产者，加入任务到list里，通知消费者来消费
 * @note   
 * @param  *task: 
 * @param  *buf: 这里就是struct __thrdpool_task_entry，为了简便写成void *buf
 * @param  *pool: 
 * @retval None
 */
inline void __threadpool_schedule(const struct threadpool_task *task, void *buf,threadpool_t *pool)
{
	printf("__threadpool_schedule\n");
	struct __threadpool_task_entry *entry = (struct __threadpool_task_entry *)buf;

	entry->task = *task;
	pthread_mutex_lock(&pool->mutex);

	// 把任务队列的任务放入线程池中
	printf("add entry list to pool task Queue\n");
	list_add_tail(&entry->list, &pool->task_queue);
    //叫醒在等待的线程
	pthread_cond_signal(&pool->cond);

	pthread_mutex_unlock(&pool->mutex);
}

/**
 * @brief 生产者
 * 
 * @param task 
 * @param pool 
 * @return int 
 */
 int  threadpool_schedule(const struct threadpool_task *task, threadpool_t *pool)
 {
	// 这是第一次调用，我们分配buf(entry)，后面我们都不需要再次malloc
	// 靠entry->task = *task 来复用entry了
	printf("threadpool_schedule\n");
    void *buf = malloc(sizeof (struct __threadpool_task_entry));
    if(buf)
    {
        __threadpool_schedule(task, buf, pool);
		return 0;
    }
    return -1;
 }
 /**
  * @brief 给线程池扩容
  * 
  * @param pool 
  * @return int 
  */
 int  threadpool_increase(threadpool_t *pool)
 {
pthread_attr_t attr;
	pthread_t tid;
	int ret;

	ret = pthread_attr_init(&attr);
	if (ret == 0)
	{
		if (pool->stacksize)
			pthread_attr_setstacksize(&attr, pool->stacksize);

		pthread_mutex_lock(&pool->mutex);
		ret = pthread_create(&tid, &attr, __threadpool_routine, pool);
		if (ret == 0)
			pool->nthreads++;

		pthread_mutex_unlock(&pool->mutex);
		pthread_attr_destroy(&attr);
		if (ret == 0)
			return 0;
	}

	errno = ret;
	return -1;
 }

/**
 * @brief 
 * 
 * @param pool 
 * @return int 
 */
int  threadpool_in_pool(threadpool_t *pool)
{
    return pthread_getspecific(pool->key) == pool;
}

/**
 * @brief 销毁线程
 * 
 * @param pending 
 * @brief 
 * 在退出时候,那些已经提交但是还没有被执行的任务,可以传入一个pending()函数,上层可以做自己的回收,回调
 * @param pool 
 */
void threadpool_destory(void (*pending)(const struct threadpool_task*),threadpool_t *pool)
{
    printf("threadpool_destory\n");
    int in_pool = threadpool_in_pool(pool);//判断是否是外部人
    struct __threadpool_task_entry *entry;
	struct list_head *pos, *tmp;

    // 1. 内部会设置pool->terminate,并叫醒所有等在队列拿任务的线程
    __threadpool_terminate(in_pool, pool);

    //2 把队列里还没有执行的任务都拿出来,通过pending返回给用户
    list_for_each_safe(pos, tmp, &pool->task_queue)
	{
		entry = list_entry(pos, struct __threadpool_task_entry, list);
		list_del(pos);
		if (pending)
			pending(&entry->task);

		free(entry);
	}
    pthread_key_delete(pool->key);
	__threadpool_destroy_locks(pool);
    //如果不是内部线程发起的销毁,要负责回收线程池内存
    if (!in_pool)
		free(pool);
}