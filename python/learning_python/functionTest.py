#!/usr/bin/python3
import sys

def f1(a, b, c): print(a,b,c)
def f2(a=10,b=11,c='he'): print(a,b,c)

def f3(*args):
    print(args)
def f4(**args):
    print(args)

def f5(*args):
    print(args)

def tracer(func, *pargs, **kargs):
    print("calling:" + func.__name__)
    return func(*pargs, **kargs)
def testf(a,b,c,d):
    return a+b+c+d
# key-word only argument, in > python3
def kwonly(a, *b, c):
    '''
    c argument must be passed by keyword syntax
    '''
    print(a, b, c)

def main(argv):
    print("enter main.")
    f1(10,11,'he')
    f1(c='he', a=10, b=11)
    f1(10, c = 'he', b=11)
    print("==========f2========")
    f2()
    f2(10)
    f2(10,11)
    f2(c='he3')
    print("=========f3========")
    f3()
    f3(10)
    f3(10,22,33)
    print("=========f4=======")
    f4()
    f4(a=1,b=2)
    print("=========f5======")
    l = [1,2,3,4,5,6,7,8]
    f5(*l)
    print("==========")
    print(tracer(testf, 1,2, c=3, d=4))
    print("====key-only argument====")
    print(kwonly(1, c = 3))

if __name__ == "__main__":
    sys.exit(main(sys.argv))
