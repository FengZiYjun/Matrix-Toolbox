// C++ matrix class
#pragma once

#include <vector>
#include <algorithm>
#include <istream>

class Matrix
{
public:
	// Constructors
	Matrix(int row, int col);
	Matrix(const std::vector<double>&);

	// Destructor
	~Matrix();

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
		Print the matrix on the console window.
	*/
	void print();

	/*
		Read from input stream.
	*/
	void read(std::istream&);

	/*
		Add a new row.
		Input: A vector of the same length as other rows in the matrix.
	*/
	void append(const std::vector<double>&);

	//
	//	Overloaded Operators
	//
	bool operator==(const Matrix&);
	bool operator!=(const Matrix&);
	Matrix& operator*(const double&);
	//friend Matrix& operator=(Matrix&, const Matrix&);
	//friend Matrix& operator*(const double&, Matrix&);

	class iterator{
	public:
		iterator();
		// Attention: the 3-th param is the size of the row.
		iterator(std::vector<std::vector<double> >::iterator&, std::vector<double>::iterator&, int);
		iterator& operator=(const iterator&);
		iterator& operator++(int);
		double operator*();
		friend bool operator==(const iterator&, const iterator&);
		friend bool operator!=(const iterator&, const iterator&);
	private:
		std::vector<std::vector<double> >::iterator iter1;
		std::vector<double>::iterator iter2;
		int _width;
		int _step;
	};
	
	iterator& begin();
	iterator& end();

private:
	int _row;
	int _col;
	std::vector<std::vector<double> > _mat;	
	iterator _begin;
	iterator _end;
};