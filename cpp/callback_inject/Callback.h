#ifndef CALLBACK_H__
#define CALLBACK_H__

#ifdef __cplusplus
extern "C"
{
#endif
    extern void Lower_Callback_Init(void* p);
    extern void Lower_Init();
#ifdef __cplusplus
}
#endif

struct Callback
{
    void* (*callback_test_create)(int num);
    void (*callback_test_print)(void* p);
};

#endif
