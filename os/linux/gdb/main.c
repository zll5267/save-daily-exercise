#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

int func2(int a2, float b2, double c2)
{
    char pc[20] = "Hello test!";
    //std::cout << "a2:" << a2 << ";b2:" << b2 << ";c2:" << c2 << std::endl;
    //std::cout << pc << std::endl;
    int count = 0;
    int *pint = (int*)malloc(sizeof(int) * 1024);
    std::cout << "pint:" << pint << std::endl;
    while (1) {
        ++count;
        pint[count] = count;
        if (count < 300) {
            sleep(2);
        } else {
            break;
        }
    }
    free(pint);
    return 2;
}

int func1(int a1, float b1, double c1)
{
    //std::cout << "a1:" << a1 << ";b1:" << b1 << ";c1:" << c1 << std::endl;
    int x = func2(2, 2, 2);
    //std::cout << "result in " << __func__ << ": " << x << std::endl;
    return 1;
}

int func0(int a0, float b0, double c0)
{
    //std::cout << "a0:" << a0 << ";b0:" << b0 << ";c0:" << c0 << std::endl;
    int x = func1(1, 1, 1);
    //std::cout << "result in " << __func__ << ": " << x << std::endl;
    return 0;
}

void* test_thread(void*)
{
    int count = 0;
    int x = func0(0, 0, 0);
    //std::cout << "result in " << __func__ << ": " << x << std::endl;
    //while (1) {
    //    ++count;
    //    if (count < 30) {
    //        sleep(2);
    //    }
    //}
    return NULL;
}

#define THREAD_NUM 2
int main()
{
    pthread_t threads[THREAD_NUM];
    memset(threads, 0, sizeof(threads));
    for (int i = 0; i < THREAD_NUM; ++i) {
        pthread_create(&threads[i], NULL, test_thread, NULL);
    }

    for (int i = 0; i < THREAD_NUM; ++i) {
        pthread_join(threads[i], NULL);
    }
    int x = func0(0, 0, 0);
    std::cout << "result in " << __func__ << ": " << x << std::endl;

    return 0;
}
