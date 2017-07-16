#include <stdio.h>
#include "test.h"

extern struct CMUnitTest _unittest_start;
extern struct CMUnitTest _unittest_end;

int main() {
    size_t test_count = &_unittest_end - &_unittest_start;
    typedef struct CMUnitTest (*tests_array)[test_count];
    tests_array tests = (tests_array)&_unittest_start;

    //printf("size of element:%ld\n", sizeof(struct CMUnitTest));
    //printf("size of element:%ld\n", sizeof(tests[0][0]));
    //printf("size of element:%ld\n", sizeof(tests[0][1]));
    //printf("size of element:%ld\n", sizeof(_unittest_start));
    //printf("size of array:%ld\n", sizeof(tests[0]));
    //printf("test_count:%ld\n", test_count);
    //printf("count of array:%ld\n", sizeof(tests[0])/sizeof(tests[0][0]));
    //printf("1 of array:%p\n", &(tests[0][0]));
    //printf("2 of array:%p\n", &(tests[0][1]));
    return cmocka_run_group_tests(tests[0], NULL, NULL);
}
