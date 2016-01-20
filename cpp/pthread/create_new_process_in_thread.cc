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

void* childRun(void* arg)
{
    printf("enter child process thread\n");
    sleep(2);
    printf("child process thread wake up after 2 seconds\n");
    //exit(0);
    //pthread_exit(0);
    return NULL;
}
void* threadRun(void* arg)
{
    if(fork() == 0)//child process
    {
        pthread_t tThread;
        pthread_attr_t tAttr;
        pthread_attr_init(&tAttr);
        pthread_attr_setdetachstate(&tAttr, PTHREAD_CREATE_DETACHED);
        printf("begin in child main\n");
        int ret = pthread_create(&tThread, &tAttr, childRun, NULL);
        if (ret)
        {
            printf("create thread fail!\n");
        }
        pthread_exit(0);
        //exit(0);
    }
    return NULL;
}

int main()
{
    pthread_t tThread;
    pthread_attr_t tAttr;
    pthread_attr_init(&tAttr);
    pthread_attr_setdetachstate(&tAttr, PTHREAD_CREATE_DETACHED);

    int ret = pthread_create(&tThread, &tAttr, threadRun, NULL);
    if (ret)
    {
        printf("create thread fail!\n");
    }
    sleep(2);
    printf("after sleep 2s in main\n");
    return 0;
}
