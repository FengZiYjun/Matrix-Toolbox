#pragma once
#include "mymatrix.h"
#include <vector>
#include <tuple>

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
	Matrix abs(const Matrix&);
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
	Matrix max(int);
	double max();
	Matrix min(int);
	double min();
	Matrix median(int);
	double median();
	double mean();
	Matrix mean(int);
	double var();
	Matrix var(int);
	// standard error
	double stderror();
	Matrix stderror(int);
	// covariance matrix
	Matrix covar();
	
	/*
		Linear Algebra 
	*/
	double norm(const Matrix&, int);
	double norm1(const Matrix&);
	double norm2(const Matrix&);
	double FrobeniusNorm(const Matrix&);

	std::tuple<Matrix> eigenDecompose(const Matrix&);
	std::tuple<Matrix> SVD(const Matrix&);
	Matrix pseudoInverse(const Matrix&);
}