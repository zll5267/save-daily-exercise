#include <iostream>

template <class T>
struct NoChecking
{
    static void Check(T*) {
        std::cout << "NoChecking::Check(T*)" << std::endl;
    }
};
template <class T>
struct EnforceNotNull
{
    class NullPointerException : public std::exception {};
    static void Check(T* ptr) {
        if (!ptr) throw NullPointerException();
    }
};
template <class T>
struct EnsureNotNull
{
    static void Check(T*& ptr)
    {
        if (!ptr) ptr = GetDefaultValue();
    }

    static T* GetDefaultValue() {
        return new T();
    }
};

template < class T,
           template <class> class CheckingPolicy,
           template <class> class ThreadingModel
         >
class SmartPtr
    : public CheckingPolicy<T>
    , public ThreadingModel<T>//TODO SmartPtr
{
public:
    SmartPtr(T* pointer) : pointee_(pointer){
        std::cout << "SmartPtr::SmartPtr(T*)" << std::endl;
    }

    T* operator->()
    {
        std::cout << "SmartPtr::operator->" << std::endl;
        typename ThreadingModel<SmartPtr>::Lock guard(*this);
        CheckingPolicy<T>::Check(pointee_);
        return pointee_;
    }
private:
    T* pointee_;
};

template <class T>
struct SingleThreaded
{
    struct Lock {
        Lock(T){
            std::cout << "SingleThreaded::Lock(T)" << std::endl;
        }
    };
};

class Widget
{
public:
    void print() {
        std::cout << "Widget::print()" << std::endl;

    }
};

typedef SmartPtr<Widget, NoChecking, SingleThreaded> WidgetPtr;
typedef SmartPtr<Widget, EnforceNotNull, SingleThreaded> SafeWidgetPtr;

int main()
{
    std::cout << "test" << std::endl;
    WidgetPtr wp(new Widget());
    wp->print();
}
