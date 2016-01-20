#include <iostream>
//#include <stdio.h>
class A;
extern void deleteP(A *a);

class A
{
    public:
        ~A();// {std::cout << "~A" << std::endl;}
};

int main()
{
    int a = sizeof(A);
    std::cout << "a:" << a << std::endl;
    A* pa = new A();
    deleteP(pa);
}
