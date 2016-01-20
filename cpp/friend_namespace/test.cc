#include "A.h"
class B
    : public A::PA
{
public:
    static const int b1 = A::PA::pa;
    static const int b2 = A::a;
};

int main()
{
    return 0;
}
