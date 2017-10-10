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
	/*
	cout<<"testing constructor "<<endl;

	double arr[] = {1., 2., 3., 4., 5., 6., 7., 8.,9.,0.};
	vector<double> vec(arr, arr+3);
	Matrix m(vec);
	m.appendRow(vector<double>(arr+3, arr+6));
	m.appendRow(vector<double>(arr+6, arr+9));
	m.appendRow(vector<double>(arr + 6, arr + 9));
	cout << "this is m" << endl;
	m.print();
	*/

	//Matrix m = Matlab::read("D:\\Courses\\DeepLearning&NerualNetwork\\matrix\\matrix\\matrix\\test\\data.csv");
	double ar[] = {-1.2, -3.2, 2.5, 4.8, -0.1, -4.2, 2.1, 2, 5, 7, };
	Matrix q(vector<double>(ar, ar + 3));
	q.appendRow(vector<double>(ar+3, ar+6));
	q.print();

	Matlab::write(q, "D:\\Courses\\DeepLearning&NerualNetwork\\matrix\\matrix\\matrix\\test\\write.csv");
	

	return 0;
}