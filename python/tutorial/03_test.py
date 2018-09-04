import numpy as np

a = np.array([0, 30, 60, 90])

radian = a*np.pi/180

print a, radian

tan_values = np.tan(radian)

print(tan_values)

arc_tan_values = np.arctan(tan_values)

print arc_tan_values
print np.degrees(arc_tan_values)

a = np.array([1.0,5.55,  123,  0.567,  25.532])
print(a)
print np.round(a)
print np.around(a)
print np.round(a, decimals=1)
print np.around(a, decimals=1)
print np.round(a, decimals=-1)
print np.around(a, decimals=-1)
print np.floor(a)

print np.ceil(a)

n1 = 16
n2 = 18

print np.binary_repr(n1)
print np.binary_repr(n2)

print np.right_shift(n1, 2)
print np.binary_repr(np.left_shift(n2, 2))

print np.binary_repr(np.bitwise_or(n1, n2))
print np.binary_repr(np.bitwise_and(n1, n2))
print np.binary_repr(np.invert(n1))
