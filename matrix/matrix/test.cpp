#include "test.h"
#include "stdafx.h"
#include <algorithm>
#include "mymatrix.h"
#include "matlab.h"
#include "specialmat.h"
// "stdafx.h" is required by VS application project.
// If you deploy the codes in other places, drop it out.

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
		double arr[] = {1,2,2,0,1,2,1,1,2,5,3,4};
		Matrix A(vector<double>(arr, arr+3));
		A.appendRow(vector<double>(arr+3, arr+6));
		A.appendRow(vector<double>(arr+6, arr+9));
		
		A.swapRow(0,1);
		//Matrix b(vector<double>(arr+9, arr+12));
		//b = b.transpose();
		A.print();
	}
	catch (MatrixException e) {
		cout << e.what();
	}

	return 0;
}