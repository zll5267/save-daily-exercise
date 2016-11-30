#include "iostream"
struct NullType {};

template <class T, class U>
class Typelist
{
    typedef T Head;
    typedef U Tail;
};

template <class T> struct Length;

template <>
struct Length<NullType>
{
    enum { value = 0 };
};

template <class T, class U>
struct Length<Typelist<T, U> >
{
    enum { value = 1 + Length<U>::value };
};

typedef Typelist<char, Typelist<signed char, Typelist<unsigned char, NullType> > > AllCharTypes;
int main()
{
    std::cout << "length of AllCharTypes: " << Length<AllCharTypes>::value << std::endl;
}
