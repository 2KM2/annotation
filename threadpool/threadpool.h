#pragma once
#include <stddef.h>
/**
 * @brief 
 * 1. 创建完线程池后,无需记录任何线程ID或对象,线程池可以通过一个等待一个的方式优雅地去结束所有线程(每一个线程都是对等的)
 * 2. 线程任务可以由另一个线程任务调起,甚至线程池正在被销毁时也可以提交下一个任务(每一个任务也是对等的)
 * 3. 线程任务也可以销毁这个线程池
 */
typedef struct __threadpool threadpool_t;
typedef struct threadpool_task
{
    /* data */
    void (*routine) (void *);//函数指针  
    void *context;//上下文
}threadpool_task;


threadpool_t *threadpool_create(size_t nthreads,size_t stacksize);

 int  threadpool_schedule(const struct threadpool_task *task, threadpool_t *pool);

int  threadpool_increase(threadpool_t *pool);

int  threadpool_in_pool(threadpool_t *pool);//判断是否是当前的pool

void threadpool_destory(void (*pending)(const struct threadpool_task*),threadpool_t *pool);


