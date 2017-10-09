#include "matlab.h"
#include "mymatrix.h"
#include "stdafx.h"
// "stdafx.h" is required by VS application project.
// If you deploy the codes in other places, drop it out.

using namespace std;


Matrix Matlab::abs(const Matrix & m)
{
	Matrix ret(m.size(0), m.size(1));
	transform(m.begin(), m.end(), ret.begin(), abs);
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

Matrix Matlab::mean(int)
{
	return Matrix();
}



double Matlab::var()
{
	return 0.0;
}

Matrix Matlab::var(int)
{
	return Matrix();
}



double Matlab::stderror()
{
	return 0.0;
}

Matrix Matlab::stderror(int)
{
	return Matrix();
}


Matrix Matlab::covar()
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
	return ret;
}

void Matlab::write(const Matrix &)
{
}



Matrix Matlab::max(int)
{
	return Matrix();
}

double Matlab::max()
{
	return 0.0;
}

Matrix Matlab::min(int)
{
	return Matrix();
}


double Matlab::min()
{
	return 0.0;
}

Matrix Matlab::median(int)
{
	return Matrix();
}



double Matlab::median()
{
	return 0.0;
}
