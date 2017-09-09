#include "stdio.h"


#define _CON_STR(a, b) _DD##a##b
#define CON_STR(a, b) _CON_STR(a, b)
#define INT32 22U
#define UINT 10L
int xxyyy() {
    return 0;
}

#define __NS2147483647  1
#define __NS2147483647L 2

#define INT_FAST32_MAX ( 100 )

#define NS_TEST_X(x) __NS##x
#define NS_TEST_Y(x) NS_TEST_X(x)

#define OTA_LOG_INFO(format, ...) printf(format, ##__VA_ARGS__)

int main(int argc, const char* argv[])
{
#ifdef INT_FAST32_MAX
    printf("xxxxxxxxxx:%d\n", __LINE__);
#else
    printf("xxxxxxxxxx%d\n", __LINE__);
#endif
    printf("&argc:%p\n", &argc);
    printf("buidin:%p\n", __builtin_frame_address(0));
    //printf("str:%s \n", CON_STR(DD, INT_FAST32_MAX));
#if NS_TEST_Y(INT_FAST32_MAXxx) == __NS2147483647 &&  NS_TEST_Y(INT_LEAST32_MAX) == __NS2147483647L &&  NS_TEST_Y(INT32_MAX) == __NS2147483647L
    printf("xxxxxxxxxx\n");
#else
    printf("yyyyyyyyyyy\n");
#endif
    //printf("xxxxx:%s", NS_TEST_Y(INT_FAST32_MAX));
    OTA_LOG_INFO("%s, %d\n", "dsf", 10);
    OTA_LOG_INFO("sdf");
}
