#include <stdio.h>

int main()
{
loc_a:
    //std::cout<< "address is:" << &&loc_a << std::endl;
    long* a = (long*)&&loc_a;
    printf("a address is:%p\n", a);
loc_b:
    long* b = (long*)&&loc_b;
    //std::cout<< "address is:" << &&loc_b << std::endl;
    printf("b address is:%p\n", b);

    printf("main address is:%p\n", main);

    printf("b-a:%d\n", b-a);
    int local;
    printf("local at %p\n", &local);
    char buf[8];
}
