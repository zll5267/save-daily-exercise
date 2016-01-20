#include <iostream>
#include "UpperClass.h"
#include "Callback.h"

UpperClass::UpperClass(int num)
    :mNum(num)
{
    std::cout << "construct UpperClass" << std::endl;
}
void UpperClass::Init()
{
    std::cout << "UpperClass::Init" << std::endl;
    Lower_Init();
}
void* UpperClass::Callback_Init()
{
    std::cout << "UpperClass::Callback_Init" << std::endl;
    static Callback cb;
    cb.callback_test_create = &UpperClass::Create;
    cb.callback_test_print = &UpperClass::print;
    Lower_Callback_Init(&cb);
    return &cb;
}
static void* sP = UpperClass::Callback_Init();

void* UpperClass::Create(int num)
{
    std::cout << "UpperClass::Create" << std::endl;
    UpperClass *p = new UpperClass(num);
    return p;
}
void UpperClass::print(void* p)
{
    std::cout << "UpperClass::print(void*)" << std::endl;
    UpperClass *uc = (UpperClass*)p;
    uc->print();
}
void UpperClass::print()
{
    std::cout << "UpperClass::print()" << std::endl;
    std::cout<< "the num is:" << mNum << std::endl;
}
