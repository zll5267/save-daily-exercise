import numpy as np
import numpy.matlib

print np.matlib.empty((2,2))
print np.matlib.zeros((2,2))
print np.matlib.ones((2,2))

print np.matlib.eye(n=3, M=4, k=-2, dtype=np.int16)
print np.matlib.eye(n=3, M=4, k=0, dtype=np.int16)
print np.matlib.eye(n=3, M=4, k=1, dtype=np.int16)
print np.matlib.eye(n=3, M=4, k=2, dtype=np.int16)
print np.matlib.eye(n=3, M=4, k=3, dtype=np.int16)

print np.matlib.identity(5, dtype=np.int8)

print "==============="
print np.matlib.rand(3, 3)
print np.matrix('1,2;3,4')
print "------------------"

# numpy.linalg.dot, vdot, inner, matmul, determinant, solve, inv
b = np.array([[6,1,1],[4,-2,5],[2,8,7]])

print b

print np.linalg.det(b)

a = np.array([[1,1,1],[0,2,5],[2,5,-1]])
print a
b = np.array([[6],[-4],[27]])
print b
print np.linalg.solve(a, b)
ainv = np.linalg.inv(a)
print np.dot(ainv,b)
