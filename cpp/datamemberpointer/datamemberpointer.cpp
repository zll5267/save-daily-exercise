#include <iostream>
#include <cstdio>

class Point {
    public:
        int x;
        double y;
        float z;
};

int main() {
    std::cout << "&Point::x is:" << &Point::x << std::endl;
    std::cout << "&Point::y is:" << &Point::y << std::endl;
    std::cout << "&Point::z is:" << &Point::z << std::endl;

    printf("&Point::x is:%d \n", &Point::x);
    printf("&Point::y is:%d \n", &Point::y);
    printf("&Point::z is:%d \n", &Point::z);
}

/* result
&Point::x is:1
&Point::y is:1
&Point::z is:1
&Point::x is:0 
&Point::y is:8 
&Point::z is:16 
   */
