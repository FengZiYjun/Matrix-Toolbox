#include "exception.h"
#include <string>
#include "stdafx.h"

MatrixException::MatrixException()
{
}

MatrixException::MatrixException(const std::string & str)
{
	message = message  +  "\n" + str;
}

const std::string & MatrixException::getMessage()
{
	return message;
}

outOfRangeExcep::outOfRangeExcep()
{
}

outOfRangeExcep::outOfRangeExcep(const std::string & str):MatrixException(str){
}

dimenDismatchExcep::dimenDismatchExcep()
{
}

dimenDismatchExcep::dimenDismatchExcep(const std::string & str) :MatrixException(str) {
}

void dimenDismatchExcep::setMessage(int r1, int c1, int r2, int c2)
{
	message = message + "\n" + 
		"Dimension (" + std::to_string(r1) + ", " + std::to_string(c1) + ") and (" +
		std::to_string(r2) + ", " + std::to_string(c2)+ ") dismatch.";
}

invalidParamExcep::invalidParamExcep()
{
}

invalidParamExcep::invalidParamExcep(const std::string & str):MatrixException(str){
}
