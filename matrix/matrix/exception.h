#pragma once
#include <exception>
#include <string>

class outOfRangeExcep : public std::exception {
public:
	outOfRangeExcep();
	outOfRangeExcep(const std::string&);

	virtual const char* what() const throw() {
		return "Matrix access out of range.";
	}
};

class dimenDismatchExcep :public std::exception {
public:
	dimenDismatchExcep();
	dimenDismatchExcep(const std::string&);

	virtual const char* what() const throw() {
		return "Matrix dimensions dismatch.";
	}
};

class invalidParamExcep :public std::exception {
public:
	invalidParamExcep();
	invalidParamExcep(const std::string&);

	virtual const char* what() const throw() {
		return "Invalid parameters.";
	}
};