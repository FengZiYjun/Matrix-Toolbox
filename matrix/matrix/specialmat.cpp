#include "stdafx.h"
#include "specialmat.h"

diagMatrix::diagMatrix(int r, double d):Matrix(r, r){
	for (int i = 0; i < r; i++) {
		this->set(i, i, d);
	}
}

diagMatrix::diagMatrix(std::vector<double> vec):Matrix(vec.size(), vec.size()){
	for (size_t i = 0; i < vec.size(); i++) {
		this->set(i, i, vec[i]);
	}
}


onesMatrix::onesMatrix(int, int)
{
}

zerosMatrix::zerosMatrix(int, int)
{
}

unitMatrix::unitMatrix(int, int)
{
}

randomMatrix::randomMatrix(int, int)
{
}
