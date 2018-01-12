#include "testlib.h"

void main_print()
{
    printf("file:%s, line:%d, func:%s\n", __FILE__, __LINE__, __func__);
}

int main()
{
    test_print();
    return 0;
}
