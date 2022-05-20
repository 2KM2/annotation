#include <pthread.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
static pthread_key_t p_key;

void *thread_func(void *arg)
{
     int *tmp1,*tmp2;

   pthread_setspecific(p_key, arg);   

    printf("in thread %d. init specific_data to %d\n", *(int *)arg, *(int *)arg);
    tmp1 = (int *)pthread_getspecific(p_key);                                  /* 获取私有键值的内容 */
    printf("get specific_data %d\n", *tmp1);

    *tmp1 = (*tmp1) * 100;                                                     /* 修改私有键值的内容 */
    printf("change specific_data to %d\n", *tmp1);

    tmp2 = (int *)pthread_getspecific(p_key);                                  /* 重新获取本线程的私有键值 */
    printf("get specific_data %d\n", *tmp2);
 
    return (void *)0;  


}


int main()
{
    int a = 1;
    int b = 2;
    pthread_t pa, pb;
    
    printf("at first: a = %d. b = %d\n", a, b);

    pthread_key_create(&p_key, NULL);                                          /* 首先创建私有数据键值 */
    
    pthread_create(&pa, NULL, thread_func, &a);                                /* 创建线程1 */
    pthread_create(&pb, NULL, thread_func, &b);                                /* 创建线程2 */

    pthread_join(pa, NULL);
    pthread_join(pb, NULL);
    
    /* 解释下pthread_join函数：它的目的是使一个线程等待另一个线程结束 */
    /* 代码中如果没有pthread_join主线程会很快结束从而使整个进程结束，创建的线程根本来不及执行 */
    /* 加入pthread_join后，主线程会一直等待直到等待的线程结束自己才结束，使创建的线程有机会执行 */
    
    printf("at last: a = %d. b = %d\n", a, b);

    return 0;
}
