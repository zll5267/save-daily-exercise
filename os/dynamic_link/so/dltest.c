#include <dlfcn.h>
#include <unistd.h>
#include "testlib.h"

typedef void (*PFunc)();

void main_print()
{
    printf("file:%s, line:%d, func:%s\n", __FILE__, __LINE__, __func__);
}

int main()
{
    void* handle0;
    handle0 = dlopen("", RTLD_LAZY);
    if (!handle0) {
        printf("dlopen \"\" failed!!\n");
    } else {
        PFunc mp = dlsym(handle0, "main_print");
        if (mp) {
            mp();
        } else {
            printf("can not found main_print!\n");
        }
        dlclose(handle0);
        handle0 = NULL;
    }

    handle0 = dlopen("", RTLD_LAZY);
    if (!handle0) {
        printf("dlopen \"\" failed!!\n");
    } else {
        PFunc mp = dlsym(handle0, "test_print");
        if (mp) {
            mp();
        } else {
            printf("can not found test_print!\n");
        }
        dlclose(handle0);
        handle0 = NULL;
    }

    do {
        void* handle1 = dlopen("libtest.so", RTLD_LAZY);
        if (!handle1) {
            printf("dlopen \"libtest.so\" failed!!\n");
        } else {
            PFunc tp = dlsym(handle1, "test_print");
            if (tp) {
                tp();
            } else {
                printf("can not found test_print!\n");
            }
            dlclose(handle1);
            handle1 = NULL;
        }

        void* handle2 = dlopen("libtest2.so", RTLD_LAZY);
        if (!handle2) {
            printf("dlopen \"libtest2.so\" failed!!\n");
        } else {
            PFunc tp = dlsym(handle2, "test_print");
            if (tp) {
                tp();
            } else {
                printf("can not found test_print!\n");
            }
            dlclose(handle2);
            handle2 = NULL;
        }
        sleep(10);
    } while (0);

    return 0;
}
