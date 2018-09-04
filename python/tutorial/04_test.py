import numpy as np

a = np.array([[3,7,5],[8,4,3],[2,4,9]])

print(a)

print np.amin(a)
print np.amin(a, 0)
print np.amin(a, 1)

print np.ptp(a)
print np.ptp(a, axis=1)
print np.ptp(a, axis=0)

#
print np.percentile(a, 100)
print np.percentile(a, 50)
print np.percentile(a, 0)

print np.median(a)
print np.median(a, 0)

print np.mean(a)
print np.mean(a, 1)

b = np.array([1, 2, 3, 4])
w = np.array([4, 3, 2, 1])

print np.average(b, weights=w)
print "============"
c = np.array([1, 2, 3])
print np.mean(c)
print np.std(c)
print np.var(c)
print np.sqrt(np.var(c))
