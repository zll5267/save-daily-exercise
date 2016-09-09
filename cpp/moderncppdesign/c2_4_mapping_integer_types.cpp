#include <iostream>

template <int v>
struct Int2Type
{
    enum { value = v };
};

template <typename T, bool isPolymorphic>
class NiftyContainer
{
private:
    void DoSomething(T* pObj, Int2Type<true>)
    {
        T* pNewObj = pObj->Clone();
        //......
    }
    void DoSomething(T* pObj, Int2Type<false>)
    {
        T* pNewObj = new T(*pObj);
        //......
    }
public:
    void DoSomething(T* pObj)
    {
        DoSomething(pObj, Int2Type<isPolymorphic>());
    }
};
