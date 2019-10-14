#define _USE_MATH_DEFINES // Place before including <cmath> for e, log2(e), log10(e), ln(2), ln(10), pi, pi/2, pi/4, 1/pi, 2/pi, 2/sqrt(pi), sqrt(2), and 1/sqrt(2)

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <ctime>

#include "MainTestFdtdMesh.hpp"

// Debug testing macros (comment out if not necessary)
//#define SKIP_GENERATE_STIFF

using namespace std;


int main(void) {

	fdtdMesh sys;

	// Read object sys (class fdtdMesh) from file
	ifstream file_obj;
	file_obj.open("fdtdMesh.txt", ios::in);
	file_obj.read((char*)&sys, sizeof(sys));

	// Reset the loaded invalid pointers (part of them, only obvious ones) 
	sys.ResetPtr();

	// Generate Stiffness Matrix
#ifndef SKIP_GENERATE_STIFF
	clock_t t5 = clock();
	int status = generateStiff(&sys);
	if (status == 0)
	{
		cout << "generateStiff Success!" << endl;
		cout << "generateStiff time is " << (clock() - t5) * 1.0 / CLOCKS_PER_SEC << " s" << endl << endl;
	}
	else
	{
		cerr << "generateStiff Fail!" << endl;
		return status;
	}
#endif

	return 0;
}