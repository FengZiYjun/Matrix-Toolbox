#include "test.h"
#include "stdafx.h"

using namespace std;

int test::test(){
	cout<<"testing constructor "<<endl;
	//Matrix m(2,2);
	double arr[] = {1., 2., 3., 4., 5., 6., 7., 8.};
	vector<double> vec(arr, arr+3);
	Matrix m(vec);
	Matrix n(vector<double>(arr+4, arr+7));
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

	//cout<<"testing Matrix::iterator iter = m.begin();"<<endl;
	//Matrix::iterator begin = m.begin();
	//Matrix::iterator end = m.end();
	//cout<<"OK"<<endl;

	//for(;begin!=end;begin++){
	//	cout<<*begin<<" ";
	//}

	//cout<<"testing copy constructor"<<endl;
	//Matrix cp(m);
	//cout<<cp.size(0)<<" "<<cp.size(1)<<endl;
	//cp.print();

	//cout<<"testing assignment operator"<<endl;
	//Matrix a = m;
	//a.print();
	//cout<<"change in a"<<endl;
	//a.append(vec);
	//a.print();
	//cout<<"for m"<<endl;
	//m.print();

	//cout<<"testing set()"<<endl;
	//m.set(0,1,21);
	//m.print();

	//cout<<"testing multiply d"<<endl;
	//m = m * 2;
	cout<<"testing + and -"<<endl;
	Matrix ans = m + n;
	ans.print();
	ans = m - n;
	ans.print();

	return 0;
}