#include <iostream>

class A {};
class B : public virtual A {};
class C : public virtual A {};
class D : public B, public C {} ;

class C1 {
    public:
        int a;
        char b;
        char c;
        char d;
};

class B1 {
    public :
        int a;
        char b;
};
class B2 {
    public:
        char c;
};
class C2 : public B1, public B2 {
    public:
        char d;
};

class B12 : public B1 {
    public:
        char c;
};
class C3 : public B12 {
    public:
        char d;
};
int main()
{
    std::cout << "sizeof empty class A:" << sizeof(A) << std::endl;
    std::cout << "sizeof class B with virtual base class A:" << sizeof(B) << std::endl;
    std::cout << "sizeof class C with virtual base class A:" << sizeof(C) << std::endl;
    std::cout << "sizeof class D with base class B & C:" << sizeof(D) << std::endl;

    /*
       -m32
sizeof empty class A:1
sizeof class B with virtual base class A:4
sizeof class C with virtual base class A:4
sizeof class D with base class B & C:8
   */

    std::cout << "sizeof C1:" << sizeof(C1) << std::endl;
    std::cout << "sizeof C2:" << sizeof(C2) << std::endl;
    std::cout << "sizeof C2:" << sizeof(C3) << std::endl;
}
