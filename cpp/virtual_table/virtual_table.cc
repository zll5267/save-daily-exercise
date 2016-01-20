#include <iostream>

typedef void (*PFUN)();

class C
{
    public:
        C(int a):value(a){}
        virtual void func1();
        virtual void func1(int);
    protected:
        virtual void func2();
        virtual void func2(int);
    private:
        virtual void func3();
        virtual void func3(int);
        int value;
};

typedef void (*PFUNI)(C*,int);

void C::func1()
{
    std::cout << "func1()" << std::endl;
}
void C::func1(int)
{
    std::cout << "func1(int) with:"<< value << std::endl;
}

void C::func2()
{
    std::cout << "func2()" << std::endl;
}
void C::func2(int)
{
    std::cout << "func2(int) with:"<< value << std::endl;
}

void C::func3()
{
    std::cout << "func3()" << std::endl;
}
void C::func3(int)
{
    std::cout << "func3(int) with:"<< value << std::endl;
}

using namespace std;

int main()
{
    cout << "enter main ..." << endl;
    C c(10);
    long** p = (long**)&c;
    ((PFUN)p[0][0])();
    ((PFUNI)p[0][1])(&c, 0);
    ((PFUN)p[0][2])();
    ((PFUNI)p[0][3])(&c, 0);
    ((PFUN)p[0][4])();
    ((PFUNI)p[0][5])(&c, 0);
    cout << "exit main ..." << endl;
}
