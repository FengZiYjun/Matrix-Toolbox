/////////////////////////////////////////////////////////////////////////
//	This file "mymatrix.h" includes the definition of class Matrix.
//	It aims to provide users with the most convenient approach to handle 
//	matrix computation. We are also exploring ways to fasten all these 
//	operations with C++. 
//	This class is being built...
////////////////////////////////////////////////////////////////////////
#pragma once

#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#include <istream>
#include <ppl.h>
#include "exception.h"

class Matrix
{
public:
	/* 
		Constructors
	*/
	Matrix();
	// Initialize with row and column
	Matrix(int, int);
	// Initialize with a vector
	Matrix(const std::vector<double>&);
	// Copy constructor
	Matrix(const Matrix&);

	/*
		Destructor
	*/
	~Matrix();

	////////////////////  Common Methods  ////////////////
	/*
		The size of the matrix. 
		Input: 0 or 1
		Output:  the number of rows or columns
	*/
	int size(int)const;

	/*
		Fetch a certain element in the matrix
		Input: row and column
		Output: an element in the matrix
	*/
	double get(int row, int col)const;

	/*
		 Set a element to a certain value
		 Input: row, colume, value
		 Output: 0 or 1 (success or failure).
	*/
	int set(int row, int col, double value);

	/*
		Print the matrix on the console window.
	*/
	void print();

	/*
		Read from input stream.
	*/
	void read(std::istream&);

	/*
		Convert matrix to std::vector
	*/
	std::vector<std::vector<double> > toVector();

	///////////////////  Scientific Computation /////////////////
	
	// row and column selecting 
	Matrix getRow(int);
	Matrix getColumn(int);

	/*
		Add a new row.
		Input: A vector of the same length as other rows in the matrix.
	*/
	void appendRow(const std::vector<double>&);
	void appendCol(const std::vector<double>&);

	// Splitting 
	// horizontal split
	std::vector<Matrix> hsplit(const std::vector<int>&);
	std::vector<Matrix> hsplit();
	// vertical split
	std::vector<Matrix> vsplit(const std::vector<int>&);
	std::vector<Matrix> vsplit();

	// sum along rows or columns (0 or 1)
	Matrix sum(int);
	// sum up all elements
	double sum();

	// Similar for product
	Matrix product(int);
	double product();

	Matrix max(int)const;
	Matrix min(int)const;


	//	transpose to make a new matrix
	Matrix transpose();

	// reverse to make a new matrix
	Matrix inverse();

	// det
	double determine();

	// trace
	double trace();

	///////////////	Overloaded Operators  ////////////////////////
	
	// Equal
	bool operator==(const Matrix&);
	// Not equal
	bool operator!=(const Matrix&);

	// multiply with a double 
	Matrix operator*(const double&);
	friend Matrix operator*(const double&, Matrix&);
	
	// multiply with a matrix
	Matrix operator*(const Matrix&);

	// plus 
	Matrix operator+(const Matrix&);
	friend Matrix operator+(const double&, Matrix&);
	
	// minus
	Matrix operator-(const Matrix&);
	friend Matrix operator-(const double&, Matrix&);
	

	// Assignment Operator
	Matrix& operator=(const Matrix&);


	/////////////////////////  Itreator  /////////////////////////////

	class iterator: public std::iterator<std::forward_iterator_tag, double>{
	public:
		iterator();
		// Attention: the 3-th param is the size of the row.
		iterator(std::vector<std::vector<double> >::iterator&, std::vector<double>::iterator&, int, int);
		iterator& operator=(const iterator&);
		iterator operator++(int);
		iterator operator++();
		double& operator*();
		friend bool operator==(const iterator&, const iterator&);
		friend bool operator!=(const iterator&, const iterator&);
	private:
		std::vector<std::vector<double> >::iterator iter1;
		std::vector<double>::iterator iter2;
		int _width;
		int _height;
		int _step;
		int _line;
	};
	
	typedef const iterator& const_iterator;

	iterator begin();
	iterator end();
	const_iterator begin()const;
	const_iterator end()const;

protected:
	// protected class for advanced construction
	Matrix(int, int, double);
	//Matrix(Matrix::const_iterator, Matrix::const_iterator);

private:
	int _row;
	int _col;
	std::vector<std::vector<double> > _mat;
	iterator _begin;
	iterator _end;
};