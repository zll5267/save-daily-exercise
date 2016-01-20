#include <iostream>

class A
{
    public:
        void printA(const std::string& str)
        {
            std::cout << "printA " << str << std::endl;
        }
        static void printA(long obj, const std::string& str)
        {
            std::cout << "static printA" << std::endl;
            ((A*)(obj))->printA(str);
        }
};

int main()
{
    A a;
    a.printA("hello World");
    A::printA((long)(&a), "ni hao");
}
