#include <iostream>

template <bool>
struct CompileTimeChecker
{
    CompileTimeChecker(...);
};

template<>
struct CompileTimeChecker<false> {};

//CompileTimeChecker<(expr) != 0> ctc(((ERROR_##msg()))); \

#define STATIC_CHECK(expr, msg) \
{ \
    class ERROR_##msg {}; \
    sizeof CompileTimeChecker<(expr) != 0> (ERROR_##msg()); \
}

template <class To,  class From>
To* safe_reinterpret_cast(From* from)
{
    STATIC_CHECK(sizeof(From) <= sizeof(To), Destination_Type_Too_Narrow);
    return reinterpret_cast<To*>(from);
}

class big {
    int i;
};
class small {
    char c;
};

int main() {
    char array[0];
    sizeof(int(0));
    std::cout << "array : " << &array << std::endl;
#if 0
    big b;
    small* s = safe_reinterpret_cast<small>(&b);
#else

    small s;
    big* b = safe_reinterpret_cast<big>(&s);
#endif
}
