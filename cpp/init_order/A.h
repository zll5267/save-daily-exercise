#ifndef __A_H_
#define __A_H_
#include "stdio.h"
//#include <iostream>
//using namespace std;

//namespace Test{
/*
class N {
public:
    N():mN(0){cout << "init" << endl;}
    N(int n):mN(n){}
    N(const N& n):mN(n.mN){}
public:
    int mN;
friend ostream& operator<<(ostream& o, const N& n);
};
*/
/*
N iA __attribute__((init_priority(200)));
class A
{
public:

};

N iB __attribute__((init_priority(199)));
class B
{
public:
};
*/

//}

/*
ostream& operator<<(ostream& o, const N& n)
{
    o<<n.mN;
    return o;
}
*/

class A
{
    public:
        A()
        {
            //std::cout << "A::constructor" << std::endl;
            printf("A::constructor\n");
        }
        int a;
};
class B
{
    public:
        B()
        {
            //std::cout << "B::constructor" << std::endl;
            printf("B::constructor\n");
        }
        int b;
};
#endif
