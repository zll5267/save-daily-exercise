import numpy as np

X = np.linspace(-np.pi, np.pi, 256, endpoint=True)
C, S = np.cos(X), np.sin(X)
print(X.dtype)
print(C.dtype)
print(S.dtype)

print(X.ndim)
Y = X.copy()
print(Y.itemsize)
Y.shape = (32, 8) #Y.reshape()
print(Y.ndim)
print(Y.flags)

x = np.empty((3,2), dtype=int)
print(x)

x = np.zeros((3,2), dtype=np.int8)
print(x.dtype)
print(x.shape)
print(x.ndim)
print(x.itemsize)
print(x)

x = np.ones([2, 2], dtype=np.int16)
print(x)
#====================

l = [1, 2, 3, 4]
s = "Hello World"
print(np.asarray(l))
print(np.frombuffer(s, dtype='S1'))
r = range(10)

print(np.fromiter(r, dtype=np.float32))

print(np.arange(10, 20, 2))
#================

print(np.linspace(10, 50, 20))
print(np.logspace(1, 10, num=10, base=2))

x=np.array([[1,2,3],[3,4,5],[5,6,7]])
print(x)
print(x.ndim)
print(x.shape)
print(x.itemsize)
print(x[...,1])
print(x[1,...])
print(x[1:,...])

rows = np.array([[0,0], [2,2]])
cols = np.array([[0,2], [0,2]])
print(x[rows, cols])
print(x[[0,0,2,2], [0,2,0,2]])

print(x[x>4])
