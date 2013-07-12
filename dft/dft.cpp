// dft.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "fftwDFT.h"


using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
															// [initialization] //////////////////////////////////////////////
	
	unsigned int size=7;									// set size of DFT
	float *test1= (float*)malloc(sizeof(float) * size);		// allocate memory for input
	float *test2= (float*)malloc(sizeof(float) * size);		// and output
	string input ="";										// add value for user's input

															// [^initialization] /////////////////////////////////////////////
	
	while (true)											// [main loop] ///////////////////////////////////////////////////
	{
		cout << "Enter number or enter 'exit'" << endl;		// show message for user
		cin >> input;										// and get input from user

															
		if(input=="exit") {									// if user enter's 'exit':
			break;											// break loop
			return 0;										// and close app
		}													

		else												// or
		{
			try												
			{												
			  *test1=::atof(input.c_str());					// try to convert input to number
			  myDFT::fftwDFT<float>::DFT(test1,size,test2); // and use it to DFT,
			  cout << *test1 << " >> " << *test2 << endl;	// then show to user result of DFT
			}												

															
			catch(exception e)								// if error: 
			{												//
				cout << e.what();							// show error message to user
			}												
		}													
	}														// [^main loop] /////////////////////////////////////////////////

	return 0;												// [exit]
}

