#include <iostream>

template <typename InIt, typename OutIt>
OutIt Copy(InIt first, InIt last, OutIt result)
{
    for (; first != last; ++first, ++result)
        *result = *first;
    return OutIt;
}

template <typename T>
class TypeTraits
{
private:
    template <class U>
    struct PointerTraits
    {
        enum { result = false };
        typedef NullType PointeeType;
    };

    template <class U>
    struct PointerTraits<U*>
    {
        enum { result = true };
        typedef U PointeeType;
    };

    template <class U>
    struct PToMTraits
    {
        enum { result = false };
    };

    template <class U, class V>
    struct PToMTraits<U V::*>//what's this mean
    {
        enum { result = true };
    };

    template <class U>
    struct UnConst
    {
        typedef U Result;
    };

    template <class U>
    struct UnConst<const U>
    {
        typedef U Result;
    };
public:
    enum { isPointer = PointerTraits<T>::result };
    typedef PointerTraits<T>::PointeeType PointeeType;
    //...
    enum { isMemberPointer = PToMTraits<T>::result };

    typedef UnConst<T>::Result NonConstType;
};
