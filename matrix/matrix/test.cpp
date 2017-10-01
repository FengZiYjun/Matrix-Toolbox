#include "test.h"
#include "stdafx.h"
#include <algorithm>
#include "mymatrix.h"
#include "matlab.h"

using namespace std;

int test::test(){
	cout<<"testing constructor "<<endl;

	double arr[] = {1., 2., 3., 4., 5., 6., 7., 8.,9.,0.};
	vector<double> vec(arr, arr+3);
	Matrix m(vec);
	m.appendRow(vector<double>(arr+3, arr+6));
	m.appendRow(vector<double>(arr+6, arr+9));
	cout << "this is m" << endl;
	m.print();

	cout << "testing vsplit" << endl;
	vector<Matrix> vofm = m.vsplit();
	for (int i = 0; i < vofm.size(); i++) {
		vofm[i].print();
	}

	return 0;
}