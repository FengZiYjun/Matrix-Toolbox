#include "test.h"
#include "stdafx.h"
#include <algorithm>
#include "mymatrix.h"

using namespace std;

int test::test(){
	cout<<"testing constructor "<<endl;

	double arr[] = {1., 2., 3., 4., 5., 6., 7., 8.};
	vector<double> vec(arr, arr+3);
	Matrix m(vec);
	
	cout<<"testing d * m"<<endl;
	Matrix p = 4.2 * m;
	p.print();

	return 0;
}