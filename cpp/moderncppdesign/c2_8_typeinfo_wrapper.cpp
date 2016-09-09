#include <iostream>

class TypeInfo
{
public:
    //Constructors / destructors
    TypeInfo(); // needed for containers
    TypeInfo(const std::type_info&);
    TypeInfo(const TypeInfo&);
    TypeInfo& operator=(const TypeInfo&);

    //Compatibility functions
    bool before(const TypeInfo&) const;
    const char* name() const;

private:
    const std::type_info* pInfo_;
};

//Comparison operators
bool operator==(const TypeInfo&, const TypeInfo&);
bool operator!=(const TypeInfo&, const TypeInfo&);
bool operator<(const TypeInfo&, const TypeInfo&);
bool operator<=(const TypeInfo&, const TypeInfo&);
bool operator>(const TypeInfo&, const TypeInfo&);
bool operator>=(const TypeInfo&, const TypeInfo&);

void Fun(Base* pObj)
{
    TypeInfo info = typeid(Derived);

    //...
    if(typeid(*pObj) == info)
    {
        //... pBase actually points to a Derived object ...
    }
    //...
}
