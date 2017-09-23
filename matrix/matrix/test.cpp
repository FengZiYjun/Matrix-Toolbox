#include "test.h"
#include "stdafx.h"

using namespace std;

int test::test(){
	cout<<"testing constructor "<<endl;
	//Matrix m(2,2);
	double arr[] = {1., 2., 3., 4., 5., 6., 7., 8.};
	vector<double> vec(arr, arr+3);
	Matrix m(vec);
	m.append(vec);
	m.append(vec);
	//Matrix n(vector<double>(arr+4, arr+7));
	//Matrix p(vector<double>(arr, arr+3));

	//cout<<"testing read()"<<endl;
	//m.read(cin);

	//cout<<"testing get()"<<endl;
	//cout<<m.get(0,2)<<endl;

	// cout<<"testing print()"<<endl;
	// m.print();

	// cout<<"testing append()"<<endl;
	// m.append(vec);
	// m.print();

	 // cout<<"testing operator*"<<endl;
	 // (m * 2.).print();
	
	// cout<<"testing size()"<<endl;
	// cout<<m.size(0)<<" "<<m.size(1)<<endl;
	
	// cout<<"testing =="<<endl;
	// cout<< (m==n)<<endl;
	// cout<< (m==m) <<endl;
	// cout<< (m==p) <<endl;
	// cout<<"testing !="<<endl;
	// cout<< (m!=n) <<endl;
	// cout<< (m!=p) <<endl;

	cout<<"testing Matrix::iterator iter = m.begin();"<<endl;
	Matrix::iterator begin = m.begin();
	Matrix::iterator end = m.end();
	cout<<"OK"<<endl;

	cout<<"testing iterator++"<<endl;
	begin++;

	return 0;
}