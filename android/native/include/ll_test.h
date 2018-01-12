#ifndef __LL_TEST_H__
#define __LL_TEST_H__

#include <android/log.h>
/*
   typedef enum android_LogPriority {
   ANDROID_LOG_UNKNOWN = 0,
   ANDROID_LOG_DEFAULT,
   ANDROID_LOG_VERBOSE,
   ANDROID_LOG_DEBUG,
   ANDROID_LOG_INFO,
   ANDROID_LOG_WARN,
   ANDROID_LOG_ERROR,
   ANDROID_LOG_FATAL,
   ANDROID_LOG_SILENT,
   } android_LogPriority;

    __android_log_write(ANDROID_LOG_WARN, "TAG", "xxxx");
	__android_log_print(ANDROID_LOG_ERROR, "TAG", "failed with errno:%d", errno);

    va_list args;
    va_start(args,format);
    __android_log_vprint(ANDROID_LOG_VERBOSS,"TAG",format,args)

    if(0 != erron){
        __android_log_assert("0!=errno","hello-jni","There is an errno");
    }
*/

#if defined(__GNUC__) && __GNUC__ >= 4
//#define LLTEST_EXPORT __attribute__((visibility("default")))
#define LLTEST_EXPORT
#elif defined(__SUNPRO_C) && (__SUNPRO_C >= 0x590)
#define LLTEST_EXPORT __attribute__((visibility("default")))
#else
#define LLTEST_EXPORT
#endif


#ifdef __cplusplus
extern "C" {
#endif

LLTEST_EXPORT void ll_hello_world(void);

LLTEST_EXPORT int ll_add(int a, int b);

LLTEST_EXPORT char* ll_get_string(const char* name);

#ifdef __cplusplus
}

#endif

#endif // __LL_TEST_H__
