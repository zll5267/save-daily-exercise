#include <iostream>
#include <cstdio>

class Point {
    public:
        Point():x(0), y(0) {
            std::cout << "Point::Point()" << std::endl;
        };
        virtual ~Point(){
            std::cout << "Point::~Point()" << std::endl;
        };
        void setX(int _x) { x = _x; };
        virtual void setZ(int _z) { };

    public:
        int x;
        int y;
};

template <typename T>
static void* GetConstructorAddress()
{
    T* p;
    __asm__ (
        "call next\n\t"
        "next:"
    );
    //p->T::T();
    __asm__ (
        "popl %%eax\n\t"
        : "=a"(p)
    );
    return p;
}

int main()
{
    //printf("first virtual func: 0x%x \n", &Point::~Point);
    printf("second virtual func: 0x%x \n", &Point::setZ);
    printf("non virtual func: 0x%x \n", &Point::setX);
    GetConstructorAddress<Point>();
    return 0;
}
