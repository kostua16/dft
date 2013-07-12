#include "stdafx.h"
#include "fftwDFT.h"
#include "fftw3.h"
#include <assert.h>


namespace myDFT
{
	void fftwDFT<float>::Constructor_fftwDFT() {					// [Construct the class] /////////////////////

		out = (float*)fftwf_alloc_real(sizeof(float));				// allocate memory for input
		in = (float*)fftwf_alloc_real(sizeof(float));				// and output
		size=0;														// set size to 0

	}																// [^Construct the class] ////////////////////

	void fftwDFT<float>::Destructor_fftwDFT(void) {					// [Destruct the class] //////////////////////

		if(plan!=NULL) fftwf_destroy_plan(plan);					// if plan exists destroy him
		if(in!=NULL) fftwf_free(in);								// if input exists free the memory that it occupies
		if(out!=NULL) fftwf_free(out);								// if output exists free the memory that it occupies

	}																// [^Destruct the class] /////////////////////

	bool fftwDFT<float>::DFT(float *signal,unsigned int size1,float *result)
	{																// [Discrete Fourier Transform for float signals] ///////////

		assert(signal != NULL);										// assert(check) that input signal exists
		assert(result != NULL);										// assert(check) that output signal exists
		assert(size1!=NULL);										// assert(check) that size of DFT exists and more than 0
		*in= *signal;												// copy value from input to temporary input value

		if(size!=NULL && plan!=NULL && size1==size)					// if we used the transformation of a given size 
																	// (we have last size not equal 0 and last size equal new size)
		{															// and the size is not empty and there is a plan
			fftwf_execute_r2r(plan,in,out);							// then use the function for transformation
		}															// using the existing plan
		else														
		{															// or we create new plan for DFT
			plan=fftwf_plan_r2r_1d(size1,in,out,FFTW_R2HC,FFTW_ESTIMATE);
			fftwf_execute(plan);									// and use function for transformation using new plan
			size=size1;												// and set temporary size for future transformations
		}
		*result=*out;												// then we copy value from temporary result to original output signal
		return true;												// and return true
	}																// [^Discrete Fourier Transform for float signals] //////////



	void fftwDFT<double>::Constructor_fftwDFT() {					// [Construct the class] /////////////////////

		out = (double*)fftw_alloc_real(sizeof(double));				// allocate memory for input
		in = (double*)fftw_alloc_real(sizeof(double));				// and output
		size=0;														// set size to 0

	}																// [^Construct the class] ////////////////////

	void fftwDFT<double>::Destructor_fftwDFT(void) {				// [Destruct the class] //////////////////////

		if(plan!=NULL) fftw_destroy_plan(plan);						// if plan exists destroy him
		if(in!=NULL) fftw_free(in);									// if input exists free the memory that it occupies
		if(out!=NULL) fftw_free(out);								// if output exists free the memory that it occupies

	}																// [^Destruct the class] /////////////////////

	bool fftwDFT<double>::DFT(double *signal,unsigned int size1,double *result)
	{																// [Discrete Fourier Transform for double signals] ///////////

		assert(signal != NULL);										// assert(check) that input signal exists
		assert(result != NULL);										// assert(check) that output signal exists
		assert(size1!=NULL);										// assert(check) that size of DFT exists and more than 0
		*in= *signal;												// copy value from input to temporary input value

		if(size!=NULL && plan!=NULL && size1==size)					// if we used the transformation of a given size 
																	// (we have last size not equal 0 and last size equal new size)
		{															// and the size is not empty and there is a plan
			fftw_execute_r2r(plan,in,out);							// then use the function for transformation
		}															// using the existing plan
		else														
		{															// or we create new plan for DFT
			plan=fftw_plan_r2r_1d(size1,in,out,FFTW_R2HC,FFTW_ESTIMATE);
			fftw_execute(plan);										// and use function for transformation using new plan
			size=size1;												// and set temporary size for future transformations
		}
		*result=*out;												// then we copy value from temporary result to original output signal
		return true;												// and return true
	}																// [^Discrete Fourier Transform for float signals] //////////

																	// [Static initialization] ////////////////////////////

																	// initialization DFT for float signals
	fftwf_plan fftwDFT<float>::plan;								// allocate memory for plan
	unsigned int fftwDFT<float>::size;								// allocate memory for temporary size
	float* fftwDFT<float>::in;										// allocate memory for temporary input signal
	float* fftwDFT<float>::out;										// allocate memory for temporary output signal
	fftwDFT<float>::Constructor fftwDFT<float>::constr;				// initialize all values

																	// initialization DFT for double signals
	fftw_plan fftwDFT<double>::plan;								// allocate memory for plan
	unsigned int fftwDFT<double>::size;								// allocate memory for temporary size
	double* fftwDFT<double>::in;									// allocate memory for temporary input signal
	double* fftwDFT<double>::out;									// allocate memory for temporary output signal
	fftwDFT<double>::Constructor fftwDFT<double>::constr;			// initialize all values

																	// [^Static initialization] ///////////////////////////
}
