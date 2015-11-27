#!/usr/bin/python

l = [123, 'spam', 1.23]
print("type of l is: %s" % type(l))
print l
print l[1]
print l[:-1]

l += [4, 5]
print l

twoDim = [ [1,3,2],
           [4,5,9],
           [10,11,12]
        ]
print twoDim

print twoDim[2]
print [row[2] for row in twoDim]
print [twoDim[i][i] for i in [0,1,2]]

import sys
print (sys.path)
