#include <stdio.h>
#include "myown.h"

static void func3(void** state) {
    printf("func:%s, line:%d\n", __func__, __LINE__);
}

static void func4(void** state) {
    printf("func:%s, line:%d\n", __func__, __LINE__);
}

myown_func_init(func3);
myown_func_init(func4);
