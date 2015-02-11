#include "matplot-opencv.hpp"
#include <iostream>

#ifndef _DEBUG
#include <Python.h>
#endif

using namespace cv;
using namespace std;

Mat anymat_to_floatmat(const Mat &src){
	if(src.type()==CV_32FC1){
		return	src;
	}else{
		Mat	dst;
		src.convertTo(dst,CV_32FC1);
		return	dst.clone();
	}
}

bool matplotcv::hist(const Mat &seq,int nBins){
#ifndef _DEBUG
	//////////////////////////////////////////////////////////////////////////
	const	string	tHistFile	=	"tHist.txt";
	FILE	*fn;
	Mat	seq1f	=	anymat_to_floatmat(seq);
	if((fn=fopen(tHistFile.c_str(),"w"))!=NULL){
		for(int i=0;i<seq1f.cols;i++){
			fprintf(fn,"%lf\t",seq1f.ptr<float>(0)[i]);
		}
		fclose(fn);

		//////////////////////////////////////////////////////////////////////////
		Py_Initialize();
		PyRun_SimpleString("from pypixkit_plot import hist;");
		PyRun_SimpleString(string(
			string("print(hist.runhist('")
			+tHistFile
			+string("',")
			+to_string((_ULonglong)nBins)
			+string("))")
			).c_str());
		cout	<<	Py_GetBuildInfo()	<<	endl;

		Py_Finalize();
	}else{
		return false;
	}

	return true;
#endif // !_DEBUG
	return false;
}


bool matplotcv::curve(const Mat &seq){
#ifndef _DEBUG

	//////////////////////////////////////////////////////////////////////////
	///// exception
	if(seq.cols!=1&&seq.rows!=1){ // should be 1D row or col
		CV_Assert(false);
		return false; 
	}

	//////////////////////////////////////////////////////////////////////////
	const	string	tHistFile	=	"tCurve.txt";
	FILE	*fn;
	Mat	seq1f	=	anymat_to_floatmat(seq);
	if((fn=fopen(tHistFile.c_str(),"w"))!=NULL){
		for(int i=0;i<seq1f.cols;i++){
			if(seq1f.rows==1){
				cout<<seq1f.ptr<float>(0)[i]<<endl;
				fprintf(fn,"%lf\t",seq1f.ptr<float>(0)[i]);
			}else{
				fprintf(fn,"%lf\t",seq1f.ptr<float>(i)[0]);
			}
		}
		fclose(fn);

		//////////////////////////////////////////////////////////////////////////
		Py_Initialize();
		PyRun_SimpleString("from pypixkit_plot import curve");
		PyRun_SimpleString(string(
			string("curve.run_curve('")
			+tHistFile
			+string("')")
			).c_str());
		cout	<<	Py_GetBuildInfo()	<<	endl;

		Py_Finalize();
	}else{
		return false;
	}

	return true;
#endif // !_DEBUG
	return false;
}

bool matplotcv::plot_surface(const cv::Mat &mat,const int stepSize){
#ifndef _DEBUG

	//////////////////////////////////////////////////////////////////////////
	const	string	tMatFile	=	"tMat.txt";
	FILE	*fn;
	Mat	tmat1f	=	anymat_to_floatmat(mat);
	if((fn=fopen(tMatFile.c_str(),"w"))!=NULL){
		for(int i=0;i<tmat1f.rows;i++){
			for(int j=0;j<tmat1f.cols;j++){
				fprintf(fn,"%lf\t",tmat1f.ptr<float>(i)[j]);
			}	
			fprintf(fn,"\n");
		}
		fclose(fn);

		//////////////////////////////////////////////////////////////////////////
		Py_Initialize();
		PyRun_SimpleString("from pypixkit_plot import plot_surface;");
		PyRun_SimpleString(string(
			string("print(plot_surface.runplot_surface('")
			+tMatFile
			+string("',")
			+to_string((_ULonglong)tmat1f.cols)
			+string(",")
			+to_string((_ULonglong)tmat1f.rows)
			+string(",")
			+to_string((_ULonglong)stepSize)
			+string("))")
			).c_str());
		cout	<<	Py_GetBuildInfo()	<<	endl;

		Py_Finalize();
	}else{
		return false;
	}

	return true;
#endif // !_DEBUG
	return false;
}




