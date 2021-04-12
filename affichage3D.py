
#import os
#import sys
# importing mplot3d toolkits, numpy and matplotlib
from mpl_toolkits import mplot3d
import numpy as np
import matplotlib.pyplot as plt

from mpl_toolkits.mplot3d import Axes3D
from matplotlib import cm
from matplotlib.ticker import LinearLocator, FormatStrFormatter

def printData(data):
	fig = plt.figure()

	# syntax for 3-D projection
	ax = plt.axes(projection ='3d')

	# defining axes
	z = np.linspace(0, 1, 100)
	z2 = np.linspace(1, 2, 100)
	x = z * np.sin(25 * z)
	y = z * np.cos(25 * z)
	x2 = z2 * np.sin(25 * z2)
	y2 = z2 * np.cos(25 * z2)
	

	c = x + y
	c2 = x2 + y2
	#ax.scatter(x, y, z, c = c)
	plt.plot(x,y,z,c)

	# syntax for plotting
	ax.set_title('test API')
	plt.show()


def printData2(data):
	return data+data+'n'

