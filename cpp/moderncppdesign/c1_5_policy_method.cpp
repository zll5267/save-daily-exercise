#include <iostream>
#include <cstdlib>

struct OpNewCreator
{
    template <class T>
    static T* Create()
    {
        return new T;
    }
};

int main()
{
}
