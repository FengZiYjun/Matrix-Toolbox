#include <stdio.h>
#include <algorithm>
#include "matrix.h"

using namespace std;

Matrix::Matrix(int row, int col): _row(row), _col(col){
	_mat.resize(_row);
	for(int i=0;i<_row;i++){
		_mat[i].resize(_col, 0.0);
	}
}

Matrix::Matrix(const vector<double>& vec){
	_col = vec.size();
	_row = 1;
	_mat.resize(_row);
	_mat[0].resize(_col, 0.0);
	copy(vec.begin(), vec.end(), _mat[0].begin());
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

}

