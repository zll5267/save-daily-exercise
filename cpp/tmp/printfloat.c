#include <stdio.h>

int main()
{
    double d1 = 1.100000000000000000000;
    float f1 = d1;
    float *fp = (float*)&d1;
    int *i1 = (int*)&f1;
    printf("f1:%.23f\n", f1);
    printf("f1:0x%lx\n", fp[0]);
    printf("i1:0x%x\n", *i1);
}
