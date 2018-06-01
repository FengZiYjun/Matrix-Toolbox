#include "test.h"
#include "stdafx.h"
#include <algorithm>
#include "mymatrix.h"
#include "matlab.h"
#include "specialmat.h"

using namespace std;

int test::test(){
	
	try {
		int arr[] = {1, 2, 3, 2, 4, 5, 3, 5, 6};
		Matrix mat;
		mat.appendRow(vector<double>(arr, arr+3));
		mat.appendRow(vector<double>(arr+3, arr + 6));
		mat.appendRow(vector<double>(arr+6, arr + 9));

		(mat.getUpper()).print();
		(mat.getLower()).print();

		/*
		double aa[] = {8, -3, 2, 4, 11, -1, 2, 1, 4};
		Matrix A;
		A.appendRow(vector<double>(aa, aa+3));
		A.appendRow(vector<double>(aa+3, aa + 6));
		A.appendRow(vector<double>(aa+6, aa + 9));

		double bb[] = {20, 33, 12};
		Matrix B(vector<double>(bb, bb + 3));
		B = B.transpose();


		Matrix x = Matlab::solve(A, B);
		cout << "Solution:" << endl;
		x.print();

		cout << "Recover:" << endl;
		(A * x).print();
		*/
	}
	catch (MatrixException e) {
		cout << e.what();
	}

	return 0;
}