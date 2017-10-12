#include "matlab.h"
#include "mymatrix.h"
#include "stdafx.h"
#include <cmath>
// "stdafx.h" is required by VS application project.
// If you deploy the codes in other places, drop it out.

using namespace std;

/*
	Actually we want to design element-wise operations
	with parallelism but our Matrix::iterator only is 
	designed for tranversal. If we want to apply parallelism
	our itrerator has to be redesigned or make it member function
	of the Matrix class.
*/

Matrix Matlab::abs(const Matrix & m)
{
	Matrix ret(m.size(0), m.size(1));
	transform(m.begin(), m.end(), ret.begin(), [&](double d) {
		return std::abs(d);
	});
	return ret;
}

Matrix Matlab::log(const Matrix & m)
{
	if (!Matlab::isPositive(m)) {
		throw new invalidParamExcep("non-positive value for log");
	}
	Matrix ret(m.size(0), m.size(1));
	transform(m.begin(), m.end(), ret.begin(), std::logf);
	return ret;
}

Matrix Matlab::exp(const Matrix & m)
{
	Matrix ret(m.size(0), m.size(1));
	transform(m.begin(), m.end(), ret.begin(), [&](double d) {
		return std::exp(d);
	});
	return ret;
}

Matrix Matlab::square(const Matrix & m)
{
	Matrix ret(m.size(0), m.size(1));
	transform(m.begin(), m.end(), ret.begin(), [&](double d) {
		return std::pow(d, 2);
	});
	return ret;
}

Matrix Matlab::power(const Matrix & m, double dd)
{
	Matrix ret(m.size(0), m.size(1));
	transform(m.begin(), m.end(), ret.begin(), [&](double d) {
		return std::pow(d, dd);
	});
	return ret;
}

Matrix Matlab::sqrt(const Matrix & m)
{
	if (!Matlab::isPositive(m)) {
		throw new invalidParamExcep("non-positive value for sqrt");
	}
	Matrix ret(m.size(0), m.size(1));
	transform(m.begin(), m.end(), ret.begin(), [&](double d) {
		return std::sqrt(d);
	});
	return ret;
}

Matrix Matlab::multiply(const Matrix & left, const Matrix & right)
{
	if ((left.size(0) != right.size(0)) || (left.size(1) != right.size(1))) {
		throw new dimenDismatchExcep(left.size(0), left.size(1), right.size(0), right.size(1));
	}
	Matrix ret(left.size(0), left.size(1));
	transform(left.begin(), left.end(), right.begin(), ret.begin(), multiplies<double>());
	return ret;
}

Matrix Matlab::plus(const Matrix & left, const Matrix & right)
{
	if ((left.size(0) != right.size(0)) || (left.size(1) != right.size(1))) {
		throw new dimenDismatchExcep(left.size(0), left.size(1), right.size(0), right.size(1));
	}
	Matrix ret(left.size(0), left.size(1));
	transform(left.begin(), left.end(), right.begin(), ret.begin(), std::plus<double>());
	return ret;
}

Matrix Matlab::minus(const Matrix & left, const Matrix & right)
{
	if ((left.size(0) != right.size(0)) || (left.size(1) != right.size(1))) {
		throw new dimenDismatchExcep(left.size(0), left.size(1), right.size(0), right.size(1));
	}
	Matrix ret(left.size(0), left.size(1));
	transform(left.begin(), left.end(), right.begin(), ret.begin(), std::minus<double>());
	return ret;
}

bool Matlab::isPositive(const Matrix & m)
{
	Matrix::const_iterator iter = find_if_not(m.begin(), m.end(), [&](double d) {
		return d > 0;
	});
	return (iter == m.end());
}

Matrix Matlab::max(const Matrix & m, int sign)
{
	return m.max(sign);
}

double Matlab::max(const Matrix & m)
{
	return *(std::max_element(m.begin(), m.end()));
}

Matrix Matlab::min(const Matrix &, int)
{
	return Matrix();
}

double Matlab::min(const Matrix &)
{
	return 0.0;
}

Matrix Matlab::median(const Matrix &, int)
{
	return Matrix();
}

double Matlab::median(const Matrix &)
{
	return 0.0;
}

double Matlab::mean(const Matrix &)
{
	return 0.0;
}

Matrix Matlab::mean(const Matrix &, int)
{
	return Matrix();
}

double Matlab::var(const Matrix &)
{
	return 0.0;
}

Matrix Matlab::var(const Matrix &, int)
{
	return Matrix();
}

double Matlab::stderror(const Matrix &)
{
	return 0.0;
}

Matrix Matlab::stderror(const Matrix &, int)
{
	return Matrix();
}

Matrix Matlab::covar(const Matrix &)
{
	return Matrix();
}


double Matlab::norm(const Matrix &, int)
{
	return 0.0;
}

double Matlab::norm1(const Matrix &)
{
	return 0.0;
}

double Matlab::norm2(const Matrix &)
{
	return 0.0;
}

double Matlab::FrobeniusNorm(const Matrix &)
{
	return 0.0;
}

std::tuple<Matrix> Matlab::eigenDecompose(const Matrix &)
{
	return std::tuple<Matrix>();
}

std::tuple<Matrix> Matlab::SVD(const Matrix &)
{
	return std::tuple<Matrix>();
}

Matrix Matlab::pseudoInverse(const Matrix &)
{
	return Matrix();
}

Matrix Matlab::read(const char* str)
{
	ifstream file;
	try {
		file.open(str);
	}
	catch(istream::failure e){
		std::cerr << "Exception opening file\n";
		throw new invalidParamExcep("file path error.");
	}
	string row;
	vector<double> vec;
	Matrix ret;

	while (getline(file, row)) {
		stringstream linestream(row);
		string value;
		double d;
		try{
			while (getline(linestream, value, ',')) {
				d = std::stod(value);
				vec.push_back(d);
			}
		}
		catch (std::exception e) {
			throw new MatrixException("failed to convert string to double.");
		}
		if (ret.size(0) == 0) {
		// first input to matrix
			ret = Matrix(vec);
		}
		else {
			ret.appendRow(vec);
		}
		vec.clear();
	}
	file.close();
	return ret;
}

void Matlab::write(const Matrix & m, const char* path)
{
	ofstream file;
	try {
		file.open(path);
	}
	catch (ostream::failure e) {
		std::cerr << "Exception opening file\n";
		throw new invalidParamExcep("file path error.");
	}
	for (int i = 0; i < m.size(0); i++) {
		for (int j = 0; j < m.size(1); j++) {
			file << m.get(i, j) << ',';
		}
		file << '\n';
	}
	file.close();
}


