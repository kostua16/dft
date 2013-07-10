#include "stdafx.h"
#include "SimpleDFT.h"
#include <complex>
#include <vector>

using namespace std;

namespace DFT
{
	/*
	template< class T >
	vector<complex<T>> SimpleDFT<class T>::DFT(vector<complex<T>> &signal)
	{
		const int S = signal.size();
		vector< complex<T> > out =CreateNewVector(S);

		for(unsigned i=0; (i < S); i++)
		{
			out[i] = CreateNewComplex();
			for(unsigned j=0; (j < S); j++)
			{
				out[i] += signal[j] * GetPolar(i,j,S);
			}
		}
		return out;
	}
	template< class T >
	vector< complex<T> > SimpleDFT<class T>::CreateNewVector(int size)
	{
		T t;
		return vector< complex<T> >(size,t);
	}
	template< class T >
	complex<T> SimpleDFT<class T>::CreateNewComplex()
	{
		T t;
		return complex<T>(t,t);
	}
	template< class T >
	complex<T> SimpleDFT<class T>::GetPolar(unsigned int i,unsigned int j,int size)
	{
		return polar<T>(1.0,-2 * PI * i * j /size);
	}
	SimpleDFT<class T>::SimpleDFT(void)
	{
		PI= 3.141592;
	}
	*/
	/*
	vector< complex<float> > SimpleDFT<float>::CreateNewVector(int size)
	{
		return vector< complex<float> >(size,0);
	}
	
	complex<float> SimpleDFT<float>::CreateNewComplex()
	{
		return complex<float>(0,0);
	}
	complex<float> SimpleDFT<float>::GetPolar(unsigned int i,unsigned int j,int size)
	{
		return polar<float>(1.0,-2 * PI * i * j /size);
	}
	*/
	SimpleDFT<float>::SimpleDFT()
	{
		PI= 3.141592;
	};
	SimpleDFT<float>::~SimpleDFT(){};

	vector<complex<float>> SimpleDFT<float>::DFT(vector<complex<float>> &signal)
	{
		const int S = signal.size();
		vector< complex<float> > out =vector< complex<float> >(S,0);

		for(unsigned i=0; (i < S); i++)
		{
			out[i] = complex<float>(0,0);
			for(unsigned j=0; (j < S); j++)
			{
				out[i] += signal[j] * polar<float>((float)1.0f,(float)(-2 * PI * i * j /S));
			}
		}
		return out;
	}

	SimpleDFT<double>::SimpleDFT()
	{
		PI= 3.141592;
	};
	SimpleDFT<double>::~SimpleDFT(){};

	vector<complex<double>> SimpleDFT<double>::DFT(vector<complex<double>> &signal)
	{
		const int S = signal.size();
		vector< complex<double> > out =vector< complex<double> >(S,0);

		for(unsigned i=0; (i < S); i++)
		{
			out[i] = complex<double>(0,0);
			for(unsigned j=0; (j < S); j++)
			{
				out[i] += signal[j] * polar<double>((double)1.0f,(double)(-2 * PI * i * j /S));
			}
		}
		return out;
	}
}