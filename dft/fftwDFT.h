#pragma once
#include "stdafx.h"
#include "fftw3.h"

namespace myDFT
{
	template<class T> class fftwDFT;

	template<>
	class fftwDFT<float>
	{
		
	public:
		//fftwDFT();
		//~fftwDFT(void);
		static void Constructor_fftwDFT(void);
		static void Destructor_fftwDFT(void);
		static bool DFT(float *signal,unsigned int size,float *result);
	private:
		static float *out;
		static float *in;
		static unsigned int size;
		static fftwf_plan plan;

		friend class Constructor;
		class Constructor 
		{
		public:
			Constructor()
				{
					fftwDFT<float>::Constructor_fftwDFT();
					//fftwDFT<float>::out = (float*)fftwf_alloc_real(sizeof(float));
					//fftwDFT<float>::in = (float*)fftwf_alloc_real(sizeof(float));
					//fftwDFT<float>::size=0;
				}
			~Constructor()
				{
					fftwDFT<float>::Destructor_fftwDFT();
					//if(fftwDFT<float>::plan!=NULL) fftwf_destroy_plan(plan);
					//if(fftwDFT<float>::in!=NULL) fftwf_free(in);
					//if(fftwDFT<float>::out!=NULL) fftwf_free(out);
				}
		};
		static Constructor constr;
	};

	


	template<>
	class fftwDFT<double>
	{
	public:
		//fftwDFT();
		//~fftwDFT(void);
		static void Constructor_fftwDFT(void);
		static void Destructor_fftwDFT(void);
		static bool DFT(double *signal,unsigned int size,double *result);
	private:
		static double *out;
		static double *in;
		static unsigned int size;
		static fftw_plan plan;

		friend Constructor;
		class Constructor 
		{
		public:
			Constructor()
				{
					fftwDFT<double>::Constructor_fftwDFT();
					//fftwDFT<double>::out = (double*)fftw_alloc_real(sizeof(double));
					//fftwDFT<double>::in = (double*)fftw_alloc_real(sizeof(double));
					//fftwDFT<double>::size=0;
				}
			~Constructor()
				{
					fftwDFT<double>::Destructor_fftwDFT();
					//if(fftwDFT<double>::plan!=NULL) fftw_destroy_plan(plan);
					//if(fftwDFT<double>::in!=NULL) fftw_free(in);
					//if(fftwDFT<double>::out!=NULL) fftw_free(out);
				}
		};
		static Constructor constr;
	};
}

