#pragma once
#include "mymatrix.h"

namespace Matlab{

	/*
		Matrix Generators
	*/
	// diagonal matrix
	Matrix diag(std::vector<double>);

	// all one matrix
	Matrix ones(int, int);

	// all zero matrix
	Matrix zeros(int, int);

	// unit matrix
	Matrix unit(int, int);

	// random matrix
	Matrix random(int, int);

	/*
		Element-wise Operations
	*/
	Matrix log(const Matrix&);
	Matrix exp(const Matrix&);
	Matrix multiply(const Matrix&, const Matrix&);
	Matrix plus(const Matrix&, const Matrix&);
	Matrix minus(const Matrix&, const Matrix&);
	Matrix divide(const Matrix&, const Matrix&);
}