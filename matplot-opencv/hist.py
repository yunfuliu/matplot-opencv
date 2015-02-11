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
import matplotlib.mlab as mlab
import matplotlib.pyplot as plt

def runhist(fname,num_bins):

    # load data
    f = open(fname,'r')
    s   =   f.readline();
    s   =   s.split()
    for i in range(0,len(s)):
        s[i]=float(s[i])

    # data
    mu = np.mean(s)     # mean of distribution
    sigma = np.std(s)   # deviation of distribution 

    # the histogram of the data
    n, bins, patches = plt.hist(s, num_bins, normed=1, facecolor='green', alpha=0.5)

    # add a 'best fit' line
    y = mlab.normpdf(bins, mu, sigma)

    # plot
    plt.plot(bins, y, 'r--')
    plt.xlabel('x axis')
    plt.ylabel('y axis')
    titles  =   'Histogram : $\mu='+str(mu)+'$, $\sigma='+str(sigma)+'$'
    plt.title(titles)
    
    # Tweak spacing to prevent clipping of ylabel
    plt.subplots_adjust(left=0.15)
    plt.show()

if __name__ == '__main__':

    runhist('vec.txt',30)





