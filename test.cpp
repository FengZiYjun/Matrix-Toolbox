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

		const Matrix b(vector<double>(arr, arr+3));
		
		//Matrix x = Matlab::solve(mat, b);
		//x.print();

		Matrix p = b * mat;
		p.print();

	}
	catch (MatrixException e) {
		cout << e.what();
	}

	return 0;
}