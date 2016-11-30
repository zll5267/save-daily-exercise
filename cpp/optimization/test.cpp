#include "RunTimeCaculate.h"

const int NUM = 10000;

void test1() {
    RunTimeCaculate tmp("test1");
    int a[NUM];
    int b[NUM];
    for (int i = 0; i < NUM; ++i) {
        a[i] = b[i];
    }
}

void test2() {
    RunTimeCaculate tmp("test2");
    typedef struct node {
        int a;
        int b;
    } NODE[NUM];
    NODE t;
    for (int i = 0; i < NUM; ++i) {
        t[i].a = t[i].b;
    }
}
int main()
{
    test1();
    test2();
    struct c1 {
        bool b;
        double d;
        short s;
        int i;
    };
    c1 c;
    std::cout << "sizeof(c1):" << sizeof(c1) << std::endl;
    std::cout << "sizeof(c):" << sizeof c << std::endl;
    return 0;
}
