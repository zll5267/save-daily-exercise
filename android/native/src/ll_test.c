#include "ll_test.h"
#include <stdio.h>
#include <string.h>

#define TAG "ll_test"

#define LOGE(...) \
      ((void)__android_log_print(ANDROID_LOG_ERROR, TAG, __VA_ARGS__))

LLTEST_EXPORT void ll_hello_world(void)
{
    __android_log_write(ANDROID_LOG_INFO, TAG, "hello world!!");
}

LLTEST_EXPORT int ll_add(int a, int b)
{
    int result = a + b;
    __android_log_print(ANDROID_LOG_INFO, TAG, "ll_add: %d!", result);
    return result;
}

LLTEST_EXPORT char* ll_get_string(const char* name)
{
    if(NULL == name) {
        __android_log_assert("NULL == name", TAG, "name should not be null!!");
    }
    static char result[64] = {0};
    snprintf(result, sizeof(result), "Hello %s!", name);
    return result;
}



