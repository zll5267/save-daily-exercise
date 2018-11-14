import numpy as np
import scipy
import scipy.spatial

print(np.__version__)
np.show_config()


Z = np.zeros(10)
print(Z)

print(np.info(np.add))

Z = np.arange(10, 50)
print(Z)

Z=Z[::-1] #reverse the array
print(Z)

Z = np.arange(0,9)
Z=Z.reshape(3,3)
print(Z)

Z = np.array([1,2,0,0,4,0])
Z = np.nonzero(Z)
print(Z) #index of the nonzero

Z = np.eye(3,3)
print(Z)

Z = np.random.random((3,3,3))
print(Z)

Zmin,Zmax = Z.min(), Z.max()
print(Zmin, Zmax)
print(Z.mean())

Z = np.ones((10,10))
Z[1:-1, 1:-1] = 0
print(Z)

print(0*np.nan)
print(np.nan == np.nan)
print(np.inf > np.nan)
print(np.nan - np.nan)
print(0.3 == 3 * 0.1)
print(3*0.1)

Z = np.diag(1+np.arange(4), k = -1)
print(Z)

Z = np.zeros((8,8), dtype=int)
Z[1::2, ::2] = 1
Z[::2, 1::2] = 1
print(Z)
Z = np.tile(np.array([[0,1],[1,0]]), (4,4))
print(Z)

print(np.unravel_index(100, (6, 7, 8)))

#normalize a matrix
Z = np.random.random((5,5))
Zmax, Zmin = Z.max(), Z.min()
Z = (Z-Zmin) / (Zmax -Zmin)
print(Z)

color = np.dtype([
        ("r", np.ubyte, 1),
        ("g", np.ubyte, 1),
        ("b", np.ubyte, 1),
        ("a", np.ubyte, 1)])

print(color)

Z = np.dot(np.ones((5,3)), np.ones((3,2)))
print(Z)

Z = np.arange(11)
Z[(3<Z) & (Z<=8)] *= -1
print(Z)

print(sum(range(5), -1))

Z = np.arange(5)
print(Z**Z)
print(2 << Z >> 2) #[0,1,2,4,8]
print(Z <- Z)
print(1j*Z)
print(Z/1/1)
#print(Z<Z>Z)
print(np.array(0) // np.array(0)) #0
print(np.array(0) // np.array(0.))#nan
print(np.array(0) / np.array(0))#0
print(np.array(0) / np.array(0.))#nan

Z = np.zeros((5,5))
Z += np.arange(5)
print(Z)

def generate():
    for x in xrange(10):
        yield x
Z = np.fromiter(generate(), dtype=float, count=-1)
print(Z)

Z = np.random.uniform(-10, +10, 10)
print(Z)
print(np.trunc(Z+np.copysign(0.5, Z)))

Z = np.linspace(0, 1, 12)
print(Z[1:-1])

Z = np.random.random(10)
print(Z)
Z.sort()
print(Z)

#np.add.reduce() -> sum
#np.allclose() -> equal

print(Z.flags)
Z.flags.writeable = False
print(Z.flags)

#cartesian coordinates -> polar cordinates
Z = np.random.random((10, 2))
X,Y = Z[:, 0], Z[:, 1]
R = np.sqrt(X**2 + Y**2)
T = np.arctan2(Y, X)
print(R)
print(T)

print(Z.argmax()) # index

#X, Y => Cauchy matrix(cij = 1/(xi-yj))
X = np.arange(5)
Y = X + 0.5
C = 1.0 / np.subtract.outer(X, Y)
print(C)
print(np.linalg.det(C))


print(np.iinfo(np.int8).min)
print(np.finfo(np.float32).max)

#np.set_printoptions(threshold=np.nan)

Z = np.arange(100)
print(Z)
v = np.random.uniform(0,100)
print(v)
index = (np.abs(Z-v)).argmin()

print(index, Z[index])

#distances between every points
Z = np.random.random((10, 2))
X,Y = np.atleast_2d(Z[:,0]), np.atleast_2d(Z[:,1])

D = np.sqrt((X-X.T)**2 + (Y-Y.T)**2)
print(D)

D = scipy.spatial.distance.cdist(Z,Z)
print(D)

#np.genfromtxt("filename.txt", delimiter=",")

Z = np.arange(9).reshape(3,3)
for index, value in np.ndenumerate(Z):
    print(index, value)
for index in np.ndindex(Z.shape):
    print(index, Z[index])

# 2D Gaussian-like array
X, Y = np.meshgrid(np.linspace(-1, 1, 10), np.linspace(-1, 1, 10))
D = np.sqrt(X*X + Y*Y)
sigma, mu = 1.0, 0.0
G = np.exp(-((D-mu)**2 / (2.0 * sigma**2)))

print(G)

X = np.random.rand(5, 10)
Y = X - X.mean(axis=1, keepdims=True)

print(X)
print(Y)

Z = np.random.randint(0, 10, (3, 3))
print(Z)
print(Z[1])
print(Z[Z[:, 1].argsort()])

Z = np.random.uniform(0, 1, 10)
print(Z)
z = 0.5
index = np.abs(Z-z).argmin()
print(index)
print(Z.flat[index])

Z = np.ones(10)
I = np.random.randint(0, len(Z), 20)
print(I)
X = np.bincount(I, minlength=len(Z))
print(X)
print(Z + X)

X= np.arange(1,7)
print(X)
I = [1, 3, 9, 3, 4, 1]
print(I)
F = np.bincount(X,I)
print(F)


