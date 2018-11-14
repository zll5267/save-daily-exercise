import random
import numpy as np
import matplotlib.pyplot as plt

ax = plt.axes([0.025, 0.025, 0.95, 0.95], polar=True)

N = 20

my_theta = [0, np.pi/2, np.pi]
my_radii = [1, 2, 4]
#my_width = [np.pi/2, np.pi/4, np.pi/8]
my_width = [0, 0, 0]
#my_bars = plt.bar(my_theta, my_radii, width=my_width, bottom=0.0)
my_bars = plt.scatter(my_theta, my_radii)
plt.plot([0,0], [0, 1], color='r')

#for r, bar in zip(my_radii, my_bars):
#    c = random.randint(0, 100) / 100.0
#    print("=====", c, "----")
#    bar.set_facecolor(plt.cm.jet(c))
#    bar.set_alpha(0.5)
#
#theta = np.arange(0.0, 2*np.pi, 2*np.pi/N)
#
#radii = 10*np.random.rand(N)
#
#width = np.pi/4*np.random.rand(N)
#
#bars = plt.bar(theta, radii, width=width, bottom=0.0)
#
ax.set_xticklabels([])
ax.set_yticklabels([])

plt.show()
