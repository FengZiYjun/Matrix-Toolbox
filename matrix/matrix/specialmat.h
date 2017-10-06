#pragma once
#include <vector>
#include "mymatrix.h"

class diagMatrix: public Matrix {
public:
	diagMatrix(int, double);
	diagMatrix(std::vector<double>);
};

class onesMatrix : public Matrix {
public:
	onesMatrix(int, int);
};

class zerosMatrix : public Matrix {
public:
	zerosMatrix(int, int);
};

class unitMatrix : public Matrix {
public:
	unitMatrix(int, int);
};

class randomMatrix : public Matrix {
public:
	randomMatrix(int, int);
};