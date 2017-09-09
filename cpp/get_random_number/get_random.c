#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"
#include "time.h"
#include "sys/time.h"
#include "pthread.h"
#include "string.h"
#include <sys/syscall.h>

pid_t gettid()
{
    return syscall(SYS_gettid);
}

void* task_run(void* ptr)
{
    struct timeval tpstart;
    gettimeofday(&tpstart, NULL);
    pid_t tid = gettid();
    unsigned int seed = (tid << 5) | tpstart.tv_usec;
    srand(seed);
    unsigned int random_n = rand();
    printf("tid:%u, timeval.tv_usec:%lu, random_n:%u \n", tid, tpstart.tv_usec, random_n);
    return NULL;
}

struct threads_info {
    int thread_num;
    pthread_t* threads;
};

static struct threads_info my_thread_info = {1000, NULL};

int main() {
    my_thread_info.threads = (pthread_t*)malloc(sizeof(pthread_t) * my_thread_info.thread_num);
    if (my_thread_info.threads == NULL) {
       printf("malloc failed!!\n");
       return -1;
   }
   memset(my_thread_info.threads, 0, sizeof(pthread_t) * my_thread_info.thread_num);

    int i = 0;
    for(; i < my_thread_info.thread_num; ++i)
    {
        pthread_attr_t attr;
        pthread_attr_init(&attr);
        pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
        int ret = pthread_create(&(my_thread_info.threads[i]), &attr, task_run, NULL);
        if(ret)
        {
            break;
        }
    }

    for (int j = 0; j < i; ++j)
    {
        pthread_join(my_thread_info.threads[i], NULL);
    }

    free(my_thread_info.threads);
    my_thread_info.threads = NULL;
    return 0;
}
