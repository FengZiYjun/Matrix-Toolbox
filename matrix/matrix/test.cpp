#include "test.h"
#include "stdafx.h"
#include <algorithm>
#include "mymatrix.h"

using namespace std;

int test::test(){
	cout<<"testing constructor "<<endl;

	double arr[] = {1., 2., 3., 4., 5., 6., 7., 8.,9.,0.};
	vector<double> vec(arr, arr+3);
	Matrix m(vec);
	m.appendRow(vector<double>(arr+3, arr+6));
	m.appendRow(vector<double>(arr+6, arr+9));
	
	cout << "testing colAppend" << endl;
	m.appendCol(vector<double>(arr, arr+3));
	m.print();

	return 0;
}