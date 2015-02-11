"""
Demo of the histogram (hist) function with a few features.

In addition to the basic histogram, this demo shows a few optional features:

    * Setting the number of data bins
    * The ``normed`` flag, which normalizes bin heights so that the integral of
      the histogram is 1. The resulting histogram is a probability density.
    * Setting the face color of the bars
    * Setting the opacity (alpha value).

"""

import numpy as np
import matplotlib.pyplot as plt

def run_curve(fname):

    # load data
    f = open(fname,'r')
    s   =   f.readline();
    s   =   s.split()
    for i in range(0,len(s)):
        s[i]=float(s[i])

    # draw line
    x = np.linspace(0, len(s)-1, num=len(s))
    plt.plot(x, s, '-', linewidth=1, color='black')

    # plot
    plt.xlabel('x axis')
    plt.ylabel('y axis')
    
    # Tweak spacing to prevent clipping of ylabel
    plt.subplots_adjust(left=0.15)
    plt.show()

if __name__ == '__main__':

    run_curve('vec.txt')






