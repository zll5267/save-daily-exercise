#include <iostream>

class A
{
    public:
        ~A();// {std::cout << "~A" << std::endl;}
};

A::~A(){
    std::cout<< "sssss" << std::endl;
}
void deleteP(A *a)
{
    delete a;
}
