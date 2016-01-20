#include "A.h"
#include "iostream"

extern A a;
extern B b;

int main()
{
    //std::cout << "Test::A::ia:" << Test::A::iA << std::endl;
    //std::cout << "Test::B::ib:" << Test::B::iB << std::endl;
    A ta = a;
    B tb = b;
    return 0;
}
