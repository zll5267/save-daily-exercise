#include <stdio.h>
#include <dlfcn.h>

typedef void (*PFUN)();

int main()
{
    const char* libname = "libtest.so";
    void* handle = dlopen(libname, RTLD_LAZY);
    if (handle == NULL)
    {
        printf("%s open failed with error: %s\n", libname, dlerror());
    }
    void* pFunc = dlsym(handle, "print");
    if (pFunc == NULL)
    {
        printf("print not found\n");
    }
    printf("handle address: 0x%p, print address is :0x%p\n", handle, pFunc);
    ((PFUN)pFunc)();


    printf("begin try the second time dlopen\n");
    void* handle2 = dlopen(libname, RTLD_LAZY);
    if (handle2 == NULL)
    {
        printf("%s open failed with error: %s\n", libname, dlerror());
    }
    printf("after try the second time dlopen, handle2:0x%p\n", handle2);
    void* pFunc2 = dlsym(handle2, "print");
    if (pFunc2 == NULL)
    {
        printf("print not found\n");
    }
    printf("print address is :0x%p\n", pFunc2);
    ((PFUN)pFunc)();
}
