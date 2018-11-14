#include <stdio.h>

void fun(int* a, int *b) {
    printf("a:%d, b:%d\n", *a, *b);
}

int main()
{
    float a = 10.0;
    float b = 5.0;
    fun(&a, &b);
}
