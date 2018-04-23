#include "test.h"
#include "stdafx.h"
#include <algorithm>
#include "mymatrix.h"
#include "matlab.h"
#include "specialmat.h"

using namespace std;

int test::test(){
	
	try {
		/*
		double ar[] = { -4.2, 2.1, 2, 5, -1.2, -3.2, 2.5, 4.8, -0.1,  7, 10.9, 11.2 };
		Matrix q(vector<double>(ar, ar + 3));
		q.appendRow(vector<double>(ar + 3, ar + 6));
		q.appendRow(vector<double>(ar + 6, ar + 9));
		//q.appendRow(vector<double>(ar + 4, ar + 7));
		q.print();
		*/
		double arr[] = {6,2,5,8,1,2,4,1,2,5,3,4,6,5,4,3,8,9,7,6};
		//double arr[] = { -1, 0, 1, 2, 3 };
		Matrix A(vector<double>(arr, arr+4));
		A.appendRow(vector<double>(arr, arr+4));
		A.appendRow(vector<double>(arr+6, arr+10));
		A.appendRow(vector<double>(arr+2, arr+6));
		A.appendRow(vector<double>(arr+1, arr+5));
		A.appendRow(vector<double>(arr+4, arr+8));
		A.print();
		
		A.transpose().print();
		
	}
	catch (MatrixException e) {
		cout << e.what();
	}

	return 0;
}