#pragma once
#include "ml.h"
#include "stdafx.h"

ml::linearClassifier::linearClassifier()
{
}

void ml::linearClassifier::train(const Matrix & train_X, const Matrix& Y)
{
	// initialize weight and bias
	int case_num = train_X.size(0);
	int feat_num = train_X.size(1);
	weights = randomMatrix(1, feat_num);
	bias = randomMatrix(1, 1).get(0, 0);

	// define preditor, loss
	Matrix Y_pred = predict(train_X);
	double loss = loss_func(Y, Y_pred);
	
	// total gradient
	// to do 
	// need expansion element-wise multiply
	//Matrix gradient = Matlab::multiply((Y - Y_pred), train_X);
}

Matrix ml::linearClassifier::predict(const Matrix & X)
{
	Matrix ret(X.size(0), 1);
	for (int t = 0; t < X.size(0); t++) {
		ret.set(t, 0, Matlab::dotProduct(X.getRow(t), weights) + bias);
	}
	return ret;
}

double ml::linearClassifier::loss_func(const Matrix & Y, const Matrix & Y_pred)
{
	return Matlab::mean(Matlab::square(Y - Y_pred));
}
