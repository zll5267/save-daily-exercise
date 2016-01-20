#include <iostream>

/*====================================*/
/*
        A<-----
        ^     |
        |     |
        |     |
        C---->B

    compile warning :
    direct base ‘A’ inaccessible in ‘C’ due to ambiguity [enabled by default]

*/
class A
{
    public:
        A(const char* str):s(str){}
        void myPrint() { std::cout << " A::myPrint() :" << s << std::endl;}
    public:
        std::string s;
};

class B: public A
{
    public:
        B(const char* str):A(str){}
};

class C: public A, public B
{
    public:
        C():A("from A"),B("from B"){}

};
/*===================================*/
class A1
{
    public:
        virtual void print() = 0;
    private:
        int a;
};

class B1
{
    public:
        virtual void hello() { std::cout << "Hello from B1" << std::endl;}
    private:
        int b;
};

class C1 : public B1, public A1
{
    public:
        void dump() { std::cout << "dump from C1" << std::endl;}
        void print() { std::cout << "print from C1" << std::endl;}
    private:
        int c;
};
/*==============================*/
int main()
{
    /*====================*/
    C c;
    A* pa = reinterpret_cast<A*>(&c);
    c.B::myPrint();
    pa->myPrint();
    /*====================*/
    C1 c1;
    std::cout << "pointer of c1 is: " << &c1 << std::endl;
    std::cout << "pointer of c1's B1 is: " << (B1*)&c1 << std::endl;
    std::cout << "pointer of c1's A1 is: " << (A1*)&c1 << std::endl;
}

