// C++ matrix class
#pragma once

#include <vector>
#include <algorithm>
#include <istream>

class Matrix
{
public:
	Matrix(int row, int col);
	Matrix(const std::vector<double>&);
	~Matrix();
	int size(int)const;
	double get(int row, int col)const;
	void print();
	void read(std::istream&);
	void append(const std::vector<double>&);

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