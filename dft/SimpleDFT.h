#pragma once
#include <vector>
#include <complex>
using namespace std;
namespace DFT
{
	template<class T> class SimpleDFT
	{
	/*
	protected:
		double PI;
		vector< complex<T> > CreateNewVector(int size);
		complex<T> CreateNewComplex();
		complex<T> GetPolar(unsigned int i,unsigned int j,int size);

	public:
		SimpleDFT(void);
		//~SimpleDFT(void);
		vector<complex<T>> SimpleDFT<class T>::DFT(vector<complex<T>> &signal);
		*/
	};

	
	template<>
	class SimpleDFT<float>
	{
	private:
		double PI;
		//vector< complex<float> > CreateNewVector(int size);
		//complex<float> CreateNewComplex();
		//omplex<float> GetPolar(unsigned int i,unsigned int j,int size);
	public:
		SimpleDFT(void);
		~SimpleDFT(void);
		vector<complex<float>> DFT(vector<complex<float>> &signal);
	};

	template<>
	class SimpleDFT<double>
	{
	private:
		double PI;
		//vector< complex<float> > CreateNewVector(int size);
		//complex<float> CreateNewComplex();
		//omplex<float> GetPolar(unsigned int i,unsigned int j,int size);
	public:
		SimpleDFT(void);
		~SimpleDFT(void);
		vector<complex<double>> DFT(vector<complex<double>> &signal);
	};


	
}

