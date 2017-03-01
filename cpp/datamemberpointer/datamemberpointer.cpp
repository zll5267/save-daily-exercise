#include <iostream>
#include <cstdio>

class Point {
    public:
        int x;
        double y;
        float z;
};

template<class WrapperType, class MemType>
void accessMember(WrapperType *p, MemType WrapperType::*pMem)
{
    std::cout << "p->*pMem:" << p->*pMem << std::endl;
}

int main() {
    std::cout << "&Point::x is:" << (&Point::x) << std::endl;
    std::cout << "&Point::y is:" << &Point::y << std::endl;
    std::cout << "&Point::z is:" << &Point::z << std::endl;

    printf("&Point::x is:%p \n", &Point::x);
    printf("&Point::y is:%p \n", &Point::y);
    printf("&Point::z is:%p \n", &Point::z);

    Point p;
    p.x = 10;
    p.y = 5.0;
    p.z = 1.0;

    accessMember(&p, &Point::x);
    accessMember(&p, &Point::y);
    accessMember(&p, &Point::z);
}

/* result
&Point::x is:1
&Point::y is:1
&Point::z is:1
&Point::x is:(nil)
&Point::y is:0x8
&Point::z is:0x10
p->*pMem:10
p->*pMem:5
p->*pMem:1

   */
