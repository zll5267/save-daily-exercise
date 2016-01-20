#include "iostream"

namespace Test {

    class A
    {
        public:
        class B
        {
        };
    };
}
using Test::A;
class Test::A::B;
class C: public A, public B
{
};

int main()
{
}
