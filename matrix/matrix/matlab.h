#pragma once
#include "mymatrix.h"
#include <vector>

namespace Matlab{

	/*
		Matrix Generators
	*/
	// diagonal matrix
	Matrix diag(std::vector<double>);

	// all-one matrix
	Matrix ones(int, int);

	// all-zero matrix
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
	Matrix square(const Matrix&);
	Matrix power(const Matrix&, double);
	Matrix sqrt(const Matrix&);
	Matrix multiply(const Matrix&, const Matrix&);
	Matrix plus(const Matrix&, const Matrix&);
	Matrix minus(const Matrix&, const Matrix&);
	Matrix divide(const Matrix&, const Matrix&);

	/*
		Statistic Operations
	*/
	double mean();
	std::vector<double> mean(int);
	double var();
	std::vector<double> var(int);
	// standard error
	double stderror();
	std::vector<double> stderror(int);

	
	
}