#include <stdio.h>
#include "myown.h"

//myown_call _myown_start;
//myown_call _myown_end;
//extern myown_call _myown_start;
//extern myown_call _myown_end;
extern myown_call _myown_start[];
extern myown_call _myown_end[];

static void func1(void** state) {
    printf("func:%s, line:%d\n", __func__, __LINE__);
}

static void func2(void** state) {
    printf("func:%s, line:%d\n", __func__, __LINE__);
}

myown_func_init(func1);
myown_func_init(func2);

void do_myown_call(void) {
    size_t func_count = _myown_end - _myown_start;
    printf("func_count:%ld\n", func_count);

    typedef myown_call (*myown_call_array)[func_count];
    myown_call_array array = (myown_call_array)_myown_start;
    printf("size of array:%ld\n", sizeof(array));
    printf("size of array[0]:%ld\n", sizeof(array[0]));
    printf("count of array:%ld\n", sizeof(array)/sizeof(array[0]));
    for(int i = 0; i < func_count; ++i) {
        _myown_start[i](NULL);
    }
    array = &_myown_start;
    printf("count of array:%ld\n", sizeof(array[0])/sizeof(array[0][0]));
    for(int i = 0; i < func_count; ++i) {
        array[0][i](NULL);
    }
}

int main(void) {
    do_myown_call();
    return 0;
}
