#include <iostream>
#include <cstdlib>
//policy
//create a new object and return the pointer.

//policy classes
template <class T>
struct OpNewCreator
{
    static T* Create()
    {
        std::cout << "OpNewCreator" << std::endl;
        return new T();
    }
protected:
    ~OpNewCreator() {}
};

template <class T>
struct MallocCreator
{
    static T* Create()
    {
        std::cout << "MallocCreator" << std::endl;
        void* buf = std::malloc(sizeof(T));
        if (!buf) return 0;
        return new(buf) T;
    };
};

template <class T>
struct PrototypeCreator
{
    PrototypeCreator(T* pObj = 0)
        : pPrototype_(pObj)
    {
    }

    T* Create()
    {
        std::cout << "PrototypeCreator" << std::endl;
        return pPrototype_ ? pPrototype_->Clone() : 0;
    }

    T* GetPrototype() { return pPrototype_; }

    void SetPrototype(T* pObj) { pPrototype_ = pObj; }

    private:
        T* pPrototype_;
};

class Widget
{
public:
    Widget* Clone() {
        return new Widget(*this);
    }
private:
    char m1;
    char m3;
    int m2;
};

// Library code 1
//template <class CreationPolicy>
//class WidgetManager : public CreationPolicy
//{
//};
//typedef WidgetManager<OpNewCreator<Widget> > MyWidgetMgr;

// Library code 2
//template <template <class Created> class CreationPolicy>
//class WidgetManager : public CreationPolicy<Widget>
//{
//};
//typedef WidgetManager<OpNewCreator> MyWidgetMgr;

// Library code 3
template <template <class Created> class CreationPolicy = OpNewCreator>
class WidgetManager : public CreationPolicy<Widget>
{
};
typedef WidgetManager<> MyWidgetMgr;
typedef WidgetManager<PrototypeCreator> MyPWidgetMgr;

int main()
{
    Widget *w = MyWidgetMgr::Create();
    std::cout << "sizeof<Widget>: " << sizeof(*w) << std::endl;

    MyPWidgetMgr mgr;
    mgr.SetPrototype(w);
    Widget *w2 = mgr.Create();
}
