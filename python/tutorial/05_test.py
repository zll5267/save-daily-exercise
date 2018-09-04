import numpy as np

a = np.array([[3,7],[9,1]])

print (a)

print np.sort(a)

print np.argsort(a)

b = np.array([3, 1, 2])

y = np.argsort(b)

print b[y]
print np.argmax(b)
print np.argmin(b)

print np.nonzero(b)

print np.where(b > 1)

condition = np.mod(b, 2) == 1

print condition

print np.extract(condition, b)

print "================="
e = np.array([1, 256, 8755], dtype=np.int16)
print e
print map(hex,e)
print e.byteswap(True)
print map(hex,e)
