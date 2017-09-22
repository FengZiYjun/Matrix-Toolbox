#include <stdio.h>
#include <algorithm>
#include "mymatrix.h"
#include "stdafx.h"

using namespace std;

Matrix::Matrix(int row, int col): _row(row), _col(col){
	_mat.resize(_row);
	for(int i=0;i<_row;i++){
		_mat[i].resize(_col, 0.0);
	}
	_begin = Matrix::iterator(_mat.begin(), _mat[0].begin());
	_end = Matrix::iterator(_mat.end()-1, (_mat.end()-1)->end());
}

Matrix::Matrix(const vector<double>& vec){
	_col = vec.size();
	_row = 1;
	_mat.resize(_row);
	_mat[0].resize(_col, 0.0);
	copy(vec.begin(), vec.end(), _mat[0].begin());
	
	_begin = Matrix::iterator(_mat.begin(), _mat[0].begin());
	_end = Matrix::iterator(_mat.end()-1, (_mat.end()-1)->end());
}

int Matrix::size(int x)const{
	if(x==0){
		return _row;
	}else if(x==1){
		return _col;
	}else{
		throw 20;
	}
}

void Matrix::print(){
	// need to be change
	for(int i=0;i<_row;i++){
		for(int j=0;j<_col;j++){
			printf("%5.2f\t", _mat[i][j]);
		}
		printf("\n");
	}
}

double Matrix::get(int r, int c)const{
	if(0 <= r && r < _row && 0 <= c && c < _col){
		return _mat[r][c];
	}else{
		throw 20;
	}
	
}

void Matrix::read(istream& is){
	double tmp = 0.;
	for(int i=0;i<_row;i++){
		for(int j=0;j<_col;j++){
			is>>tmp;
			_mat[i][j] = tmp;
		}
		
	}
}

void  Matrix::append(const vector<double>& vec){
	if(vec.size() != _col){
		throw 20;
	}else{
		_row++;
		_mat.push_back(vector<double>(vec.begin(), vec.end()));
	}
}

Matrix::~Matrix(){}

bool Matrix::operator==(const Matrix& m){
	if(this == &m){
		return true;
	}
	if(m.size(0)!=_row || m.size(1)!=_col){
		return false;
	}else{
		bool flag = true;
		for(int i=0;i<_row;i++){
			for(int j=0;j<_col;j++){
				if(this->get(i, j) != m.get(i, j)){
					flag = false;
					break;
				}
			}
			if(flag==false){
				break;
			}
		}
		if(flag==true){
			return true;
		}else{
			return false;
		}
	}
	
}

bool Matrix::operator!=(const Matrix& m){
	return !((*this) == m);
}


Matrix& Matrix::operator*(const double& d){
	return *this;
}

Matrix::iterator& Matrix::begin(){
	return _begin;
}

Matrix::iterator& Matrix::end(){
	return _end;
}


// Definition of Public Member Functions of the sub-class - Matrix::iterator

Matrix::iterator::iterator(std::vector<std::vector<double> >::iterator& outer, 
	std::vector<double>::iterator& inner){
		this->iter1 = outer;
		this->iter2 = inner;
}



Matrix::iterator::iterator(){
	
}

Matrix::iterator& Matrix::iterator::operator=(const iterator& iter){
	this->iter1 = iter.iter1;
	this->iter2 = iter.iter2;
	return *this;
}

