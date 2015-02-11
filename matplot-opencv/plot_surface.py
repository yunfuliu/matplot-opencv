
from mpl_toolkits.mplot3d import axes3d
import matplotlib.pyplot as plt
from matplotlib import cm
import numpy as np

def runplot_surface(fname,cols,rows,stepsize):

    # load data
    f = open(fname,'r')
    Z = np.zeros((rows,cols))
#    print Z
    count = 0;
    for line in f:        
        if count < rows:
            s   =   line.split()
            for j in range(0,cols):
#                print count,j
                Z[count][j]=float(s[j])
            count=count+1
#    print Z

    # get X and Y coordinates
    X = np.outer(np.ones(rows),np.linspace(0,cols-1,cols).transpose())
    Y = np.outer(np.linspace(0,rows-1,rows),np.ones(cols).transpose())

    # shift coordinate
    X = X -(cols-1)/2
    Y = Y -(rows-1)/2    
#    print X
#    print Y

    # plot_surface
    fig = plt.figure()
    ax = fig.gca(projection='3d')
    surf =ax.plot_surface(X, Y, Z, rstride=stepsize, cstride=stepsize, alpha=0.6,cmap=cm.coolwarm)
#    fig.colorbar(surf, shrink=0.5, aspect=5)
   
    # plot profile    
    cset = ax.contour(X, Y, Z, zdir='z', offset=0, cmap=cm.coolwarm)
    cset = ax.contour(X, Y, Z, zdir='x', offset=-(cols-1)/2, cmap=cm.coolwarm)
    cset = ax.contour(X, Y, Z, zdir='y', offset=(rows-1)/2, cmap=cm.coolwarm)

    # set details
    ax.set_xlabel('X')
    ax.set_xlim(-(cols-1)/2, (cols-1)/2)
    ax.set_ylabel('Y')
    ax.set_ylim(-(rows-1)/2, (rows-1)/2)
    ax.set_zlabel('Z')
#    ax.set_zlim(-100, 100) # auto
    plt.show()

if __name__ == '__main__':

    runplot_surface('filter.txt',5,5,1)
