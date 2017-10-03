#include <stdio.h>
#include <algorithm>
#include <functional>
#include "mymatrix.h"
#include "stdafx.h"
// "stdafx.h" is required by VS application project.
// If you deploy the codes in other places, drop it out.

#define D_SCL_SECURE_NO_WARNINGS

using namespace std;

Matrix::Matrix()
{

}

Matrix::Matrix(int row, int col): _row(row), _col(col){
	_mat.resize(_row);
	for(int i=0;i<_row;i++){
		_mat[i].resize(_col, 0.0);
	}
	_begin = Matrix::iterator(_mat.begin(), _mat[0].begin(), _mat[0].size());
	_end = Matrix::iterator(_mat.end()-1, (_mat.end()-1)->end(), _mat[0].size());

}

Matrix::Matrix(const vector<double>& vec){
	_col = vec.size();
	_row = 1;
	_mat.resize(_row);
	_mat[0].resize(_col, 0.0);
	copy(vec.begin(), vec.end(), _mat[0].begin());
	
	_begin = Matrix::iterator(_mat.begin(), _mat[0].begin(), _mat[0].size());
	_end = Matrix::iterator(_mat.end()-1, (_mat.end()-1)->end(), _mat[0].size());
}

Matrix::Matrix(const Matrix& m){
	this->_row = m._row;
	this->_col = m._col;
	this->_mat = m._mat;
	this->_begin = Matrix::iterator(_mat.begin(), _mat[0].begin(), _mat[0].size());
	this->_end = Matrix::iterator(_mat.end()-1, (_mat.end()-1)->end(), _mat[0].size());
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
	// Original printing
	for(int i=0;i<_row;i++){
		for(int j=0;j<_col;j++){
			printf("%5.2f\t", _mat[i][j]);
		}
		printf("\n");
	}
}

double Matrix::get(int r, int c)const{
	// perform range check
	if(0 <= r && r < _row && 0 <= c && c < _col){
		return _mat[r][c];
	}else{
		throw 20;
	}
	
}


int Matrix::set(int row, int col, double value){
	// perform range check
	int ret = 0;
	if(row < _row && col < _col){
		_mat[row][col] = value;
	}else{
		ret = 1;
	}
	return ret;
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

std::vector<std::vector<double>> Matrix::toVector()
{
	return _mat;
}

void  Matrix::appendRow(const vector<double>& vec){
	if(vec.size() != _col){
		throw 20;
	}else{
		_row++;
		_mat.push_back(vector<double>(vec.begin(), vec.end()));
	}
}

void Matrix::appendCol(const vector<double>& vec){
	if (vec.size() != _row) {
		throw 20;
	} else {
		_col++;
		for (int i = 0; i < _row; i++) {
			_mat[i].push_back(vec[i]);
		}
	}
}

Matrix::~Matrix(){}

bool Matrix::operator==(const Matrix& m){
	// change to STL?
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


Matrix& Matrix::operator=(const Matrix& m){
	this->_row = m._row;
	this->_col = m._col;
	this->_mat = m._mat; 
	this->_begin = Matrix::iterator(_mat.begin(), _mat[0].begin(), _mat[0].size());
	this->_end = Matrix::iterator(_mat.end()-1, (_mat.end()-1)->end(), _mat[0].size());
	return *this;
}


Matrix Matrix::operator*(const double& d){
	using namespace placeholders;
	Matrix ret(_row, _col);
	transform(_begin, _end, ret._begin, bind(multiplies<double>(), d, placeholders::_1));
	return ret;
}

Matrix operator*(const double& d, Matrix& m){
	Matrix ret(m.size(0), m.size(1));
	transform(m.begin(), m.end(), ret.begin(), bind(multiplies<double>(), d, placeholders::_1));
	return ret;
}


Matrix::iterator& Matrix::begin(){
	return _begin;
}

Matrix::iterator& Matrix::end(){
	return _end;
}


Matrix Matrix::operator*(const Matrix& m){
	using namespace concurrency;
	if (_col != m._row) {
		throw 20;
	}
	Matrix ret(_row, m._col);
	parallel_for(0, _row, [&](int i) {
		for (int t = 0; t < m._col; t++) {
			double tmp = 0.;
			for (int j = 0; j < m._row; j++) {
				tmp += _mat[i][j] * m._mat[j][t];
			}
			ret.set(i, t, tmp);
		}
	});
	return ret;
}

Matrix Matrix::operator+(const Matrix& m){
	Matrix ret(m._row, m._col);
	transform(_begin, _end, m._begin, ret._begin, plus<double>());
	return ret;
}

Matrix operator+(const double& d, Matrix& m){
	Matrix ret(m.size(0), m.size(1));
	transform(m.begin(), m.end(), ret.begin(), bind(plus<double>(), placeholders::_1, d));
	return ret;
}

Matrix Matrix::operator-(const Matrix& m){
	Matrix ret(m._row, m._col);
	transform(_begin, _end, m._begin, ret._begin, minus<double>());
	return ret;
}


Matrix operator-(const double& d, Matrix& m){
	Matrix ret(m._row, m._col);
	transform(m.begin(), m.end(), ret.begin(), bind(minus<double>(), d, placeholders::_1));
	return ret;
}

Matrix Matrix::transpose(){
	Matrix ret(_col, _row);
	for (int i = 0; i < _row; i++) {
		for (int j = 0; j < _col; j++) {
			ret._mat[j][i] = _mat[i][j];
		}
	}
	return ret;
}

double Matrix::determine(){
	// to do
	return 0;
}

double Matrix::trace()
{
	int diag = min<int>(_row, _col);
	double trace = 1.0;
	for (int i = 0; i < diag; i++) {
		trace *= _mat[i][i];
	}
	return trace;
}

Matrix Matrix::getRow(int row_index){
	// range check
	if (row_index >= _row || row_index < 0 ) {
		throw 20;
	}
	return Matrix(_mat[row_index]);
}


Matrix Matrix::getColumn(int col_index){
	Matrix ret(_row, 1);
	using namespace concurrency;
	parallel_for(0, _row, [&](int i) {
		ret.set(i, 0, _mat[i][col_index]);
	});
	return ret;
}

vector<Matrix> Matrix::hsplit(const vector<int>& vec){
	using namespace concurrency;
	vector<Matrix> ret;
	for (size_t i = 0; i < vec.size(); i++) {
		Matrix m(_row, 1);
		parallel_for(0, _row, [&](int row) {
			m.set(row, 0, _mat[row][vec[i]]);
		});
		ret.push_back(m);
	}
	return ret;
}

std::vector<Matrix> Matrix::hsplit()
{
	vector<int> v;
	for (int i = 0; i < _col; i++) {
		v.push_back(i);
	}
	return hsplit(v);
}


vector<Matrix> Matrix::vsplit(const vector<int>& vec){
	vector<Matrix> ret;
	for (size_t i = 0; i < vec.size(); i++) {
		ret.push_back(Matrix(_mat[vec[i]]));
	}

	return ret;
}

std::vector<Matrix> Matrix::vsplit()
{
	vector<int> v;
	for (int i = 0; i < _row; i++) {
		v.push_back(i);
	}
	return vsplit(v);
}

Matrix Matrix::inverse(){
	// to do

	return *this;
}


Matrix Matrix::sum(int i){
	// to do

	return *this;
}

double Matrix::sum(){
	// to do

	return 0;
}


Matrix Matrix::product(int i){
	// to do 

	return *this;
}

double Matrix::product(){
	// to do

	return 0;
}


// Definition of Public Member Functions of the sub-class - Matrix::iterator

Matrix::iterator::iterator(std::vector<std::vector<double> >::iterator& outer, 
	std::vector<double>::iterator& inner, int width){
		this->iter1 = outer;
		this->iter2 = inner;
		this->_width = width;
		this->_step = 0;
}



Matrix::iterator::iterator(){
	this->_step = 0;

}


Matrix::iterator& Matrix::iterator::operator=(const iterator& iter){
	this->iter1 = iter.iter1;
	this->iter2 = iter.iter2;
	this->_width = iter._width;
	return *this;
}

Matrix::iterator Matrix::iterator::operator++(int){
	Matrix::iterator ret(*this);
	if(_step < _width){
		iter2++;
	}else{
		iter1++;
		iter2 = iter1->begin();
		_step = 0;
	}
	return ret;
}

Matrix::iterator Matrix::iterator::operator++(){
	if(_step < _width){
		iter2++;
	}else{
		iter1++;
		iter2 = iter1->begin();
		_step = 0;
	}
	return *this;	
}

bool operator==(const Matrix::iterator& left, const Matrix::iterator& right){
	if(left.iter1 == right.iter1 && left.iter2 == right.iter2){
		return true;
	}else{
		return false;
	}
}

bool operator!=(const Matrix::iterator& left, const Matrix::iterator& right){
	return !(left == right);
}

double& Matrix::iterator::operator*(){
	return *iter2;
}