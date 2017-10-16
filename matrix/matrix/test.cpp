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
	
	double ar[] = {-1.2, -3.2, 2.5, 4.8, -0.1, -4.2, 2.1, 2, 5, 7, 10.9, 11.2};
	Matrix q(vector<double>(ar, ar + 3));
	q.appendRow(vector<double>(ar+3, ar+6));
	q.appendRow(vector<double>(ar + 6, ar + 9));
	q.appendRow(vector<double>(ar + 4, ar + 7));
	q.print();

	Matrix p(vector<double>(ar, ar+3));
	Matrix r = Matlab::multiply(p, q);
	r.print();
	r = Matlab::multiply(q, p);
	r.print();

	return 0;
}