#include "matlab.h"
#include "mymatrix.h"
#include "stdafx.h"
// "stdafx.h" is required by VS application project.
// If you deploy the codes in other places, drop it out.

using namespace std;
Matrix Matlab::diag(std::vector<double>)
{
	return Matrix();
}

Matrix Matlab::ones(int, int)
{
	return Matrix();
}

Matrix Matlab::zeros(int, int)
{
	return Matrix();
}

Matrix Matlab::unit(int, int)
{
	return Matrix();
}

Matrix Matlab::random(int, int)
{
	return Matrix();
}

Matrix Matlab::log(const Matrix &)
{
	return Matrix();
}

Matrix Matlab::exp(const Matrix &)
{
	return Matrix();
}

Matrix Matlab::square(const Matrix &)
{
	return Matrix();
}

Matrix Matlab::power(const Matrix &, double)
{
	return Matrix();
}

Matrix Matlab::sqrt(const Matrix &)
{
	return Matrix();
}

Matrix Matlab::multiply(const Matrix &, const Matrix &)
{
	return Matrix();
}

Matrix Matlab::plus(const Matrix &, const Matrix &)
{
	return Matrix();
}

Matrix Matlab::minus(const Matrix &, const Matrix &)
{
	return Matrix();
}

double Matlab::mean()
{
	return 0.0;
}

vector<double> Matlab::mean(int)
{
	return vector<double>();
}

double Matlab::var()
{
	return 0.0;
}

std::vector<double> Matlab::var(int)
{
	return std::vector<double>();
}

double Matlab::stderror()
{
	return 0.0;
}

std::vector<double> Matlab::stderror(int)
{
	return std::vector<double>();
}
