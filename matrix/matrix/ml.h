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
	/*
		Constructors: specify the number of iteration
	*/
	linearClassifier(int);
	void train(const Matrix&, const Matrix&);
	Matrix predict(const Matrix&);
	double loss_func(const Matrix&, const Matrix&);
private:
	Matrix weights;
	double bias;
	// should inheritate
	void _matrix_check(const Matrix&);
};

class ml::neuralNetwork {

};
