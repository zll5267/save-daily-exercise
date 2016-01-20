#include <unistd.h>
#include <sys/types.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

/*
   *difference between exit and pthread_exit
   *exit will call _exit will kill the whole process
   *pthread_exit only exit the current thread.
   */

void* threadRun(void* arg)
{
    printf("enter thread\n");
    sleep(2);
    printf("thread wake up after 2 seconds\n");
    //exit(0);
    pthread_exit(0);
    return NULL;
}

int main()
{
    pthread_t tThread;
    pthread_attr_t tAttr;
    pthread_attr_init(&tAttr);
    pthread_attr_setdetachstate(&tAttr, PTHREAD_CREATE_DETACHED);
    printf("begin in main\n");

    int ret = pthread_create(&tThread, &tAttr, threadRun, NULL);
    if (ret)
    {
        printf("create thread fail!\n");
    }
    printf("after create thread in main\n");
    pthread_exit(0);
    //sleep(5);
    printf("after sleep 5s in main\n");
    return 0;
}
