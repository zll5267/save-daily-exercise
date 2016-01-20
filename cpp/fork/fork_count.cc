#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>

int main()
{
    int i;
    for(i = 0; i < 2; ++i)
    {
        fork();
        printf("g");
    }
    wait(NULL);
    return 0;
}
