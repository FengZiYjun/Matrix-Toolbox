#pragma once
/*
	This is the head file for machine learning algorithm implemented by 
	Matrix class defined in mymatrix.h and Matlab class defined in matlab.h. 
	The design of this class encapsulates as much algorithm details as possible
	for convenient APIs. 
*/
#include "mymatrix.h"
#include "matlab.h"
#include "specialmat.h"
#include "exception.h"


namespace ml {
	class linearClassifier;
	class ligisticClassifier;
	class neuralNetwork;
};

class ml::ligisticClassifier {

};

class ml::linearClassifier {
public:
	linearClassifier();
	void train(const Matrix&);
	Matrix predict(const Matrix&);
private:
	Matrix weights;
};

class ml::neuralNetwork {

};
