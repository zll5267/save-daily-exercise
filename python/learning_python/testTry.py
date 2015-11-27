#!/usr/bin/python3

try:
    raise Exception()
except:
    print('got exception')
finally:
    print('in finally')
print('after try')

try:
    #raise Exception()
    print('in try')
except:
    print('got exception')
else:
    print('no execption')
finally:
    print('in finally')
print('after try')
