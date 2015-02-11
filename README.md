# matplot-opencv

The purpose of this library is to draw line, histogram, and 1D and 2D curve for data analysis. 
Also, this library take the advantage of the most popular matplotlib as the core functionality of drawing.  

System requirements:
--------------------
 * Python > 3.0
 * OpenCV > 2.0
 * numpy
 * matplotlib

Sample code:
------------
Sample codes of three functions are shown below:


 * Draw a 2D filter
~~~.cpp
#include <opencv2/imgproc/imgproc.hpp>
#include <matplot-opencv.hpp>
using namespace cv;
namespace plt = matplotcv;
void main(){
    Mat	mat = (Mat_<float>(3,3)<<1,2,1,2,4,2,1,2,1);
    plt::plot_surface(mat);
}
~~~
Result: ![plot_surface example](./example/plot_surface.png)


 * Draw a histogram
~~~.cpp
#include <opencv2/imgproc/imgproc.hpp>
#include <matplot-opencv.hpp>
using namespace cv;
namespace plt = matplotcv;
void main(){
    Mat seq = (Mat_<float>(1,4)<<1,2,3,2);
    plt::hist(seq,3);
}
~~~
Result: ![hist example](./example/hist.png)


 * Draw a 1D curve
~~~.cpp
#include <opencv2/imgproc/imgproc.hpp>
#include <matplot-opencv.hpp>
using namespace cv;
namespace plt = matplotcv;
void main(){
    Mat seq = (Mat_<float>(1,4)<<1,4,2,5);
    plt::curve(seq);
}
~~~
Result: ![curve example](./example/curve.png)

