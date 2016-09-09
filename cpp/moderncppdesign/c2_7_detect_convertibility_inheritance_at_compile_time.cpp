#include <iostream>

/*
typedef char Small;
class Big { char dummy[2]; };

Small Test(U);
Big Test(...);

T MakeT();
const bool convExists = sizeof(Test(MakeT())) == sizeof(Small);
*/

//test if T can convert to U
template <class T, class U>
class Conversion
{
    typedef char Small;
    class Big { char dummy[2]; };
    static Small Test(U);
    static Big Test(...);
    static T MakeT();
public:
    enum { exists = sizeof(Test(MakeT())) == sizeof(Small) };
    enum { sameType = false };
};

template <class T>
class Conversion<T, T>
{
public:
    enum { exists = 1, sameType = 1 };
};

#define SUPERSUBCLASS(T, U) \
    (Conversion<const U*, const T*>::exists && \
    !Conversion<const T*, const void*>::sameType)

// const U* converts implicitly to const T* only under 3 cases
//1. T is the same type as U .
//2. T is an unambiguous public base of U .
//3. T is void .


int main()
{
    cout << Conversion<double, int>::exists << ' ' << std::endl;;
}
