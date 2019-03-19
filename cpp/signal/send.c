#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

struct customer_type {
    float f;
    int i;
};


int main(int argc, char **argv)
{
    if(argc != 2){
        fprintf(stderr,"usage:%s pid\n",argv[0]);
        exit(EXIT_FAILURE);
    }
    pid_t pid = atoi(argv[1]);
    sleep(2);
    union sigval mysigval;
    struct customer_type *ct = malloc(sizeof(struct customer_type));
    ct->f = 1.11;
    ct->i = 222;
    mysigval.sival_ptr= ct;
    printf("sending val: %p,f:%f,i:%d......\n", ct, ct->f, ct->i);
    printf("sending SIGINT signal to %d......\n",pid);
    if(sigqueue(pid,SIGINT,mysigval) == -1){
        perror("sigqueue error");
        exit(EXIT_FAILURE);
    }
    return 0;
}

