#include <iostream>

template < class T,
           template <class> class CheckingPolicy
         >
class SmartPtr : public CheckingPolicy<T>
{
    template< class T1, template <class> class CP1>
    SmartPtr(const SmartPtr<T1, CP1>& other)
        : pointee_(other.pointee_), CheckingPolicy<T>(other)
    {
    }
};

/*
   initialize a SmartPtr<Widget, EnforceNotNull> with a
   SmartPtr<ExtendedWidget, NoChecking>

   ExtendedWidget* -> Widget* is ok, ExtendedWidget inherit from Widget;

   NoChecking -> EnforceNotNull, need some kind of other code support:
   1. EnforceNotNull implements a constructor that accepts a NoChecking object
   2. NoChecking implements a conversion operator to EnforceNotNull
*/
