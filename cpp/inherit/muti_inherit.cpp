#include "iostream"

class IInterface{};

class IObject: /*virtual*/ public IInterface{};

class ISynchronize: /*virtual*/ public IInterface{};

class IWeakReferenceSource: /*virtual*/ public IInterface{};

class Object: public IObject, ISynchronize, IWeakReferenceSource{};

class Device: virtual public Object{};

int main()
{
    Object o;
    Device d;
    IInterface* i = &d;

}
