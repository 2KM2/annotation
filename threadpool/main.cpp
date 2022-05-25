#include "threadpool.h"
#include <stdio.h>
#include <unistd.h>
void my_routine(void *context)                                                   
{
   // 我们要执行的函数                    
    printf(">>task-%llu start.\n", reinterpret_cast<unsigned long long>(context));
    sleep(1);
}                                                                              

void my_pending(const struct threadpool_task *task) 
{
  // 线程池销毁后，没执行的任务会到这里
    printf("pending task-%llu.\n", reinterpret_cast<unsigned long long>(task->context));                                   
} 



int main()
{

    threadpool_t *thrd_pool = threadpool_create(48, 1024); // 创建                            
    struct threadpool_task task;
    unsigned long long i;
                               
   for (i = 0; i < 10000; i++)
   {
       task.routine = &my_routine;                                             
       task.context = reinterpret_cast<void *>(i);                             
       threadpool_schedule(&task, thrd_pool); // 调用
   }
    getchar(); // 卡住主线程，按回车继续
    threadpool_destory(&my_pending, thrd_pool); // 结束
    return 0;                  
}


