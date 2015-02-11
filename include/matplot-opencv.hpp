#include <opencv2/imgproc/imgproc.hpp>

#ifndef __MATPLOTCV_HPP__
#define __MATPLOTCV_HPP__

namespace matplotcv{

	/*
	*	@param		seq:	it should be a 1D sequence of 1f value. 
	*	@param		nBins:	Number of bins. 
	*/
	bool hist(const cv::Mat &seq,int nBins);

	/*
	*	@param		seq:	it should be 1D sequence of 1f value. 
	*/
	bool curve(const cv::Mat &seq);

	/*
	*	@param		stepSize: adjust the step size of x and y axis. The larger number, gets a sparser grids. 
	*/
	bool plot_surface(const cv::Mat &mat,const int stepSize=1);

}
#endif


