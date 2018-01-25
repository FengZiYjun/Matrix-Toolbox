#pragma once
#include "ml.h"
#include "stdafx.h"
#define MAX_Iter 1000

ml::linearClassifier::linearClassifier(int iteration = MAX_Iter)
{
}

void ml::linearClassifier::train(const Matrix & train_X, const Matrix& Y)
{
	_matrix_check(train_X);
	_matrix_check(Y);
	// initialize weight and bias
	int case_num = train_X.size(0);
	int feat_num = train_X.size(1);
	weights = randomMatrix(1, feat_num);
	bias = randomMatrix(1, 1).get(0, 0);

	// define preditor, loss
	Matrix Y_pred = predict(train_X);
	double loss = loss_func(Y, Y_pred);
	double loss_threshold = 1e-3;
	
	/*
		start optimization£º 
		to do: early stopping, regulization
	*/
	for (int iter = 0; iter < MAX_Iter; iter++) {
		if (loss <= loss_threshold) {
			break;
		}
		// need testing 
		Matrix gradient_w = Matlab::multiply((Y - Y_pred), train_X);
		weights = weights - gradient_w;
		double gradient_b = (Y - Y_pred).sum();
		bias = bias - gradient_b;
		Y_pred = predict(train_X);
		loss = loss_func(Y, Y_pred);

	}

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

void ml::linearClassifier::_matrix_check(const Matrix &)
{
}


