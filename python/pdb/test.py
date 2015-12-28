#!/usr/bin/python
if __name__ == "__main__":
    import sys
    print("__file__:" + __file__)
    print("__lineno__:" + str(sys._getframe().f_lineno))
    a = 1
    import pdb
    pdb.set_trace()
    b = 2
    c = a + b
    print(c)
