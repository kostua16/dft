// dft.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
//#include <stdio.h>
#include "SimpleDFT.h"
#include <vector>
#include <complex>
#include <iostream>



using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	vector< complex<double> > numbers;

	numbers.push_back(102023);
	numbers.push_back(102023);
	numbers.push_back(102023);
	numbers.push_back(102023);

	DFT::SimpleDFT<double> f=DFT::SimpleDFT<double>();
	vector<complex<double>> testing = f.DFT(numbers);
	for(unsigned i=0; (i < testing.size()); i++)
	{
		cout << testing[i] << endl;	
	}
	string end1;
	cout << "Press any key and hit RETURN to exit." << endl;
	cin >> end1;
	return 0;
}

