#include <iostream>
#include "matrix.h"

using namespace std;

int main(){
	cout<<"testing constructor "<<endl;
	//Matrix m(2,2);
	double arr[] = {1., 2., 3., 4.};
	vector<double> vec(arr, arr+3);
	Matrix m(vec);

	//cout<<"testing read()"<<endl;
	//m.read(cin);

	//cout<<"testing get()"<<endl;
	//cout<<m.get(0,2)<<endl;

	cout<<"testing print()"<<endl;
	m.print();

	cout<<"testing append()"<<endl;
	m.append(vec);
	m.print();

}