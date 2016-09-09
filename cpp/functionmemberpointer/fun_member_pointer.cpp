#include <iostream>
#include <cstdio>

class Point {
    public:
        virtual ~Point(){};
        void setX(int _x) { x = _x; };
        virtual void setZ(int _z) { };

    public:
        int x;
        int y;
};

int main()
{
    //printf("first virtual func: 0x%x \n", &Point::~Point);
    printf("second virtual func: 0x%x \n", &Point::setZ);
    printf("non virtual func: 0x%x \n", &Point::setX);
    return 0;
}
