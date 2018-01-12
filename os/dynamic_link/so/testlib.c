#include "testlib.h"

void test_print()
{
    printf("file:%s, line:%d\n", __FILE__, __LINE__);
}

void test_lib()
{
    printf("func:%s\n", __func__);
}
