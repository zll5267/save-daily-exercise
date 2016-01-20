#include <iostream>
#include "LowerClass.h"
#include "Callback.h"

static struct Callback *callback;

void Lower_Callback_Init(void* p)
{
    std::cout << "Lower_Callback_Init" << std::endl;
    callback = (struct Callback*)p;
}

void Lower_Init()
{
    std::cout << "Lower_Init" << std::endl;
    if (callback == NULL)
    {
        std::cout << "callback is not initialized" << std::endl;
        return;
    }
    void *p = callback->callback_test_create(100);
    LowerClass lc(p);
    callback->callback_test_print(p);
}

LowerClass::LowerClass(void* p):up(p)
{
    std::cout << "LowerClass::LowerClass" << std::endl;
}
