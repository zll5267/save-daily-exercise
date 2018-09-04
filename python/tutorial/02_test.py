import numpy as np

a = np.arange(0, 60, 5)
a = a.reshape(3,4)
print(a)

for x in np.nditer(a):
    print x

b = a.T
print(b)
