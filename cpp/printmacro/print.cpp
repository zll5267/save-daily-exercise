#include <iostream>
#include "show_m.h"

#define ass void()

SHOW_MACRO(ass)

int main()
{
    std::cout << "hello world!" << std::endl;
}
