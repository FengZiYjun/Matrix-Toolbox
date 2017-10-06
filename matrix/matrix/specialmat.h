#pragma once
#include <vector>
#include <algorithm>
#include "mymatrix.h"
#include <stdlib.h>

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

class unitMatrix : public diagMatrix {
public:
	unitMatrix(int);
};

class randomMatrix : public Matrix {
public:
	randomMatrix(int, int);
};