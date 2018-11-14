#include "stdio.h"

static int pow2gt (int x)
{
    --x;

    x |= x >> 1;
    x |= x >> 2;
    x |= x >> 4;
    x |= x >> 8;
    x |= x >> 16;

    return x + 1;
}

int main()
{
    int x[] = {10, 30, 50, 128, 256, 500};
    int n = sizeof(x)/ sizeof(int);
    for (int i = 0; i < n; ++i) {
        printf("x=%d, ", x[i]);
        printf("pow2gt:%d\n", pow2gt(x[i]));
    }
}

