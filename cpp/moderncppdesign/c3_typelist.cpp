#include <iostream>

template <class T, class U>
struct Typelist
{
    typedef T Head;
    typedef U Tail;
};

namespace TL
{
    //typelist algorithms
}

typedef Typelist<char, Typelist<signed char, Typelist<unsigned char, NullType> > > AllCharTypes;

typedef Typelist<int, NullType> OneTypeOnly;

//macro helper
#define TYPELIST_1(T1) Typelist<T1, NullType>
#define TYPELIST_2(T1, T2) Typelist<T1, TYPELIST_1(T2)>
#define TYPELIST_3(T1, T2, T3) Typelist<T1, TYPELIST_2(T2, T3)>
#define TYPELIST_4(T1, T2, T3, T4) Typelist<T1, TYPELIST_3(T2, T3, T4)>

//#define TYPELIST_50(...) ...
typedef TYPELIST_4(signed char, short int, int, long int) SignedIntegrals;

template <class TList> struct Length;

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

template <class TList, unsigned int index> struct TypeAt;

template <class Head, class Tail>
struct TypeAt<Typelist<Head, Tail>, 0>
{
    typedef Head Result;
};

template <class Head, class Tail, unsigned int i>
struct TypeAt<Typelist<Head, Tail>, i>
{
    typedef typename TypeAt<Tail, i-1>::Result Result;
};

template <class TList, class T>
struct IndexOf;

template <class T>
struct IndexOf<NullType, T>
{
    enum { value = -1 };
};

template <class T, class Tail>
struct IndexOf<Typelist<T, Tail>, T>
{
    enum { value = 0 };
};

template <class Head, class Tail, class T>
struct IndexOf<Typelist<Head, Tail>, T>
{
private:
    enum { temp = IndexOf<Tail, T>::value };
public:
    enum { value = temp == -1 ? -1 : 1 + temp };
};

template <class TList, class T> struct Append;
template <>
struct Append<NullType, NullType>
{
    typedef NullType Result;
};

template <class T>
struct Append<NullType, T>
{
    typedef TYPELIST_1(T) Result;
};

template <class Head, class Tail>
struct Append<NullType, Typelist<Head, Tail> >
{
    typedef Typelist<Head, Tail> Result;
};

template <class Head, class Tail, class T>
struct Append<Typelist<Head, Tail>, T>
{
    typedef Typelist<Head, typename Append<Tail, T>::Result> Result;
};

typedef Append<SignedIntegrals, TYPELIST_3(float, double, long double)>::Result SignedTypes;

//remove only the first occurrence
template <class TList, class T> struct Erase;

template <class T>
struct Erase<NullType, T>
{
    typedef NullType Result;
};

template <class T, class Tail>
struct Erase<Typelist<T, Tail>, T>
{
    typedef Tail Result;
};

template <class Head, class Tail, class T>
struct Erase<Typelist<Head, Tail>, T>
{
    typedef Typelist<Head, typename Erase<Tail, T>::Result> Result;
};

template <class TList, class T> struct EraseAll;

template <class T>
struct EraseAll<NullType, T>
{
    typedef NullType Result;
};

template <class T, class Tail>
struct EraseAll<Typelist<T, Tail>, T>
{
    //Go all the way down the list removing the type
    typedef typename EraseAll<Tail, T>::Result Result;
};

template <class Head, class Tail, class T>
struct EraseAll<Typelist<Head, Tail>, T>
{
    // Go all the way down the list removing the type
    typedef Typelist<Head, typename EraseAll<Tail, T>::Result> Result;
};

template <class TList> struct NoDuplicates;

template <>
struct NoDuplicates<NullType>
{
    typedef NullType Result;
};

template <class Head, class Tail>
struct NoDuplicates<Typelist<Head, Tail> >
{
private:
    typedef typename NoDuplicates<Tail>::Result L1;
    typedef typename Erase<L1, Head>::Result L2;
public:
    typedef Typelist<Head, L2> Result;
};

template <class TList, class T, class U>
struct Replace;

template <class T, class U>
struct Replace<NullType, T, U>
{
    typedef NullType Result;
};

template <class T, class Tail, class U>
struct Replace<Typelist<T, Tail>, T, U>
{
    typedef Typelist<U, Tail> Result;
};

template <class Head, class Tail, class T, class U>
struct Replace<Typelist<Head, Tail>, T, U>
{
    typedef Typelist<Head, typename Replace<Tail, T, U>::Result> Result;
};

template <class TList, class T>
struct MostDerived;

template <class T>
struct MostDerived<NullType, T>
{
    typedef T Result;
};

template <class Head, class Tail, class T>
struct MostDerived<Typelist<Head, Tail>, T>
{
private:
    typedef typename MostDerived<Tail, T>::Result Candidate;
public:
    typedef typename Select<SUPERSUBCLASS(Canidate, Head), Head, Candidate>::Result Result;
};


template <class T> struct DerivedToFront;

template <>
struct DerivedToFront<NullType>
{
    typedef NullType Result;
};

template <class Head, class Tail>
struct DerivedToFront<Typelist<Head, Tail> >
{
private:
    typedef typename MostDerived<Tail, Head>::Result TheMostDerived;
    typedef typename Replace<Tail, TheMostDerived, Head>::Result L;
public:
    typedef Typelist<TheMostDerived, L> Result;
};

//---------------------------------------------------------
template <class TList, template <class> class Unit>
class GenScatterHierarchy;

// GenScatterHierarchy specialization: Typelist to Unit
template <class T1, class T2, template <class> class Unit>
class GenScatterHierarchy<Typelist<T1, T2>, Unit>
    : public GenScatterHierarchy<T1, Unit>
    , public GenScatterHierarchy<T2, Unit>
{
public:
    typedef Typelist<T1, T2> TList;
    typedef GenScatterHierarchy<T1, Unit> LeftBase;
    typedef GenScatterHierarchy<T2, Unit> RightBase;
};

// Pass an atomic type (non-typelist) to Unit
template <class AtomicType, template <class> class Unit>
class GenScatterHierarchy
    : public Unit<AtomicType>
{
    typedef Unit<AtomicType> LeftBase;
};

// Do nothing for NullType
template <template <class> class Unit>
class GenScatterHierarchy<NullType, Unit>
{
};


