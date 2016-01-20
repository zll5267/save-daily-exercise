#include <iostream>

using std::cout;
using std::endl;

#define EIID_IInterface 0
#define EIID_IObject 1
#define EIID_ISyncronize 2

class IInterface
{
    public:
        virtual IInterface* Probe(int id) = 0;
};

class IObject
:virtual public IInterface
{
};

class ISyncronize
:virtual public IInterface
{
};


class Object
:public IObject, public ISyncronize
{
    public:
        IInterface* Probe(int id)
        {
            if (id == EIID_IObject)
            {
                return (IInterface*)(IObject*)(this);
            }
            else if (id == EIID_ISyncronize)
            {
                return (IInterface*)(ISyncronize*)(this);
            }
            else if (id == EIID_IInterface)
            {
                return (IInterface*)(IObject*)(this);
            }
            else
            {
                return NULL;
            }

        }
};

class A
:public Object
{
    public:
        A():value(0){}
        int value;
};


int main()
{
    A *pa = new A();
    pa->value = 100;

    IInterface *pInterface = pa->Probe(EIID_IInterface);
    //IObject *pObject = (IObject*)pa->Probe(EIID_IObject);
    IObject *pObject = dynamic_cast<IObject*>(pa->Probe(EIID_IObject));
    //ISyncronize *pSyncronize = (ISyncronize*)pa->Probe(EIID_ISyncronize);
    ISyncronize *pSyncronize = dynamic_cast<ISyncronize*>(pa->Probe(EIID_ISyncronize));


    A *pO = (A*)pObject;
    A *pS = (A*)pSyncronize;
    //A *pIO = (A*)(IObject*)pInterface;
    A *pIO = (A*)dynamic_cast<IObject*>(pInterface);
    //A *pIS = (A*)(ISyncronize*)pInterface;
    A *pIS = (A*)dynamic_cast<ISyncronize*>(pInterface);
    cout << "IObject* -> A*::value: " << pO->value << endl;
    cout << "ISyncronize* -> A*::value: " << pS->value << endl;
    cout << "IInterface* -> IObject* -> A*::value: " << pIO->value << endl;
    cout << "IInterface* -> ISyncronize* -> A*::value: " << pIS->value << endl;
    return 0;
}
