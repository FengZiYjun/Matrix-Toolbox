#pragma once
#include <exception>
#include <string>
#include "stdafx.h"

class MatrixException :public std::exception {
public:
	MatrixException();
	MatrixException(const std::string&);
	const std::string& getMessage();
protected:
	std::string message;
};


class outOfRangeExcep : public MatrixException {
public:
	outOfRangeExcep();
	outOfRangeExcep(const std::string&);
};

class dimenDismatchExcep :public MatrixException {
public:
	dimenDismatchExcep();
	dimenDismatchExcep(const std::string&);
	void setMessage(int, int, int, int);
};

class invalidParamExcep :public MatrixException {
public:
	invalidParamExcep();
	invalidParamExcep(const std::string&);
};