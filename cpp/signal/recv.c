#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

struct customer_type {
    float f;
    int i;
};

void sighandler(int signo, siginfo_t *info,void *ctx);
//给自身传递信息
int main(void)
{

    struct sigaction act;
    act.sa_sigaction = sighandler;
    sigemptyset(&act.sa_mask);
    act.sa_flags = SA_SIGINFO;//信息传递开关
    if(sigaction(SIGINT,&act,NULL) == -1){
        perror("sigaction error");
        exit(EXIT_FAILURE);
    }
    for(; ;){
        printf("waiting a SIGINT signal....\n");
        pause();
    }
    return 0;
}

void sighandler(int signo, siginfo_t *info,void *ctx)
{
    //以下两种方式都能获得sigqueue发来的数据
    printf("receive the data from siqueue by info->si_int is %d\n",info->si_int);
    printf("receive the data from siqueue by info->si_value.sival_int is %d\n",info->si_value.sival_int);
    printf("receive the data from siqueue by info->si_value.sival_int is %p\n",info->si_value.sival_ptr);
    struct customer_type *ct = (struct customer_type*)(info->si_value.sival_ptr);
    printf("f:%f, i:%d \n", ct->f, ct->i);

}

