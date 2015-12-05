#!/usr/bin/python3

import zope.interface
class IFoo(zope.interface.Interface):
    """Foo Blash Blash"""
    x = zope.interface.Attribute("""x blah blah""")

    def bar(q, r=None):
        """bar in IFoo"""

#object provide interfaces, class implement interfaces
@zope.interface.implementer(IFoo)
class Foo:
#error    zope.interface.implements(IFoo)

    def __init__(self, x=None):
        self.x = x
    def bar(self, q, r=None):
        return q, r, self.x
    def __repr__(self):
        return "Foo(%s)" % self.x
#Foo implements IFoo, the instances of Foo provide IFoo
class IFooFactory(zope.interface.Interface):
    """Create foos"""
    def __call__(x=None):
        """Create a foo
        The argument provides the initial value for x ....
        """
zope.interface.directlyProvides(Foo, IFooFactory)
print(list(zope.interface.providedBy(Foo)))
print(Foo().__init__.__doc__)
@zope.interface.provider(IFooFactory)
class Foo2:
#error    zope.interface.classProvides(IFooFactory)
    def __init__(self, x = None):
        self.x = x
    def bar(self, q, r=None):
        return q, r, self.x
    def __repr__(self):
        return "Foo(%s)" %self.x

print(list(zope.interface.providedBy(Foo2)))

if __name__ == "__main__":
    print("test begin....")
    print("type(IFoo):" + str(type(IFoo)))
    print("access IFoo's member begin ")
    x = IFoo['x']
    bar = IFoo.get('bar')
    names = list(IFoo)
    print(x)
    print(bar)
    print("bar's signature:" + bar.getSignatureString())
    print(names)
    print("access IFoo's member end")
    print("implement privide begin")
    print(IFoo.implementedBy(Foo))
    foo = Foo()
    print(IFoo.providedBy(foo))
    print("implement privide end")

