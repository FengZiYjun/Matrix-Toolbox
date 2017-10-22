#include <stdio.h>
#include <algorithm>
#include <numeric>
#include <functional>
#include "mymatrix.h"
#include "stdafx.h"
// "stdafx.h" is required by VS application project.
// If you deploy the codes in other places, drop it out.

#define D_SCL_SECURE_NO_WARNINGS

using namespace std;

Matrix::Matrix():_row(0),_col(0){

}

Matrix::Matrix(int row, int col): _row(row), _col(col){
	_mat.resize(_row);
	for(int i=0;i<_row;i++){
		_mat[i].resize(_col, 0.0);
	}
	_begin = Matrix::iterator(_mat.begin(), _mat[0].begin(), _mat[0].size(), _mat.size());
	_end = Matrix::iterator(_mat.end()-1, (_mat.end()-1)->end(), _mat[0].size(), _mat.size());

}

Matrix::Matrix(const vector<double>& vec){
	_col = vec.size();
	_row = 1;
	_mat.resize(_row);
	_mat[0].resize(_col, 0.0);
	copy(vec.begin(), vec.end(), _mat[0].begin());
	
	_begin = Matrix::iterator(_mat.begin(), _mat[0].begin(), _mat[0].size(), _mat.size());
	_end = Matrix::iterator(_mat.end()-1, (_mat.end()-1)->end(), _mat[0].size(), _mat.size());
}

Matrix::Matrix(const Matrix& m){
	this->_row = m._row;
	this->_col = m._col;
	this->_mat = m._mat;
	this->_begin = Matrix::iterator(_mat.begin(), _mat[0].begin(), _mat[0].size(), _mat.size());
	this->_end = Matrix::iterator(_mat.end()-1, (_mat.end()-1)->end(), _mat[0].size(), _mat.size());
}

int Matrix::size(int x)const{
	if(x==0){
		return _row;
	}else if(x==1){
		return _col;
	}else{
		
		throw new invalidParamExcep("in Matrix::size()");
	}
}

void Matrix::print(){
	// next line information is needed to print matrix 
	// but iterator does not provide such information.
	for(int i=0;i<_row;i++){
		for(int j=0;j<_col;j++){
			printf("%f\t", _mat[i][j]);
		}
		printf("\n");
	}
}

double Matrix::get(int r, int c)const{
	// perform range check
	if(0 <= r && r < _row && 0 <= c && c < _col){
		return _mat[r][c];
	}else{
		throw new outOfRangeExcep("in Matrix::get()");
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
	if(_col != 0 && vec.size() != _col){
		// dimension dismatch excep
		throw new dimenDismatchExcep("in Matrix::appendRow()");
	}else{
		if (_col == 0) {
			_col = vec.size();
		}
		_row++;
		_mat.push_back(vector<double>(vec.begin(), vec.end()));
		_begin = Matrix::iterator(_mat.begin(), _mat[0].begin(), _mat[0].size(), _mat.size());
		_end = Matrix::iterator(_mat.end() - 1, (_mat.end() - 1)->end(), _mat[0].size(), _mat.size());
	}
}

void Matrix::appendCol(const vector<double>& vec){
	if (_row != 0 && vec.size() != _row) {
		// dimension dismatch excep
		throw new dimenDismatchExcep("in Matrix::appendCol()");
	} else {
		if (_row == 0) {
			_row = vec.size();
		}
		_col++;
		for (int i = 0; i < _row; i++) {
			_mat[i].push_back(vec[i]);
		}
		_begin = Matrix::iterator(_mat.begin(), _mat[0].begin(), _mat[0].size(), _mat.size());
		_end = Matrix::iterator(_mat.end() - 1, (_mat.end() - 1)->end(), _mat[0].size(), _mat.size());
	}
}

void Matrix::appendRow(const Matrix & m)
{
	if (_col != m._col) {
		throw new dimenDismatchExcep(_row, _col, m._row, m._col);
	}
	for_each(m._mat.begin(), m._mat.end(), [&](const vector<double>& vec) {
		this->appendRow(vec);
	});
	
}

void Matrix::appendCol(const Matrix & m) 
{
	if (_row != m._row) {
		throw new dimenDismatchExcep(_row, _col, m._row, m._col);
	}
	using namespace concurrency;
	parallel_for(0, m._col, [&](int t){
		parallel_for(0, _row, [&](int i) {
			_mat[i].push_back(m._mat[i][t]);
		});
	});
	_col += m._col;
	_begin = Matrix::iterator(_mat.begin(), _mat[0].begin(), _mat[0].size(), _mat.size());
	_end = Matrix::iterator(_mat.end() - 1, (_mat.end() - 1)->end(), _mat[0].size(), _mat.size());
}

void Matrix::swapRow(int a, int b)
{
	// no check
	_mat[a].swap(_mat[b]);
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
	this->_begin = Matrix::iterator(_mat.begin(), _mat[0].begin(), _mat[0].size(), _mat.size());
	this->_end = Matrix::iterator(_mat.end()-1, (_mat.end()-1)->end(), _mat[0].size(), _mat.size());
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


Matrix::iterator Matrix::begin(){
	return _begin;
}

Matrix::iterator Matrix::end(){
	return _end;
}

const Matrix::iterator & Matrix::begin() const
{
	return _begin;
}

const Matrix::iterator & Matrix::end() const
{
	return _end;
}

Matrix::Matrix(int r, int c, double d):_row(r), _col(c){
	_mat.resize(_row);
	for (int i = 0; i<_row; i++) {
		_mat[i].resize(_col, d);
	}
	_begin = Matrix::iterator(_mat.begin(), _mat[0].begin(), _mat[0].size(), _mat.size());
	_end = Matrix::iterator(_mat.end() - 1, (_mat.end() - 1)->end(), _mat[0].size(), _mat.size());
}


Matrix Matrix::operator*(const Matrix& m){
	using namespace concurrency;
	if (_col != m._row) {
		// dimension dismatch excep
		throw new dimenDismatchExcep("in Matrix::operator*(Matrix)");
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

Matrix Matrix::operator-(const Matrix& m)const{
	Matrix ret(m._row, m._col);
	transform(_begin, _end, m._begin, ret._begin, minus<double>());
	return ret;
}

Matrix Matrix::operator/(double d)
{
	if (d == 0) {
		throw new invalidParamExcep("divided by zero.");
	}
	Matrix ret(_row, _col);
	transform(begin(), end(), ret.begin(), bind(divides<double>(), placeholders::_1, d));
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

double Matrix::determinant(){

	return (this->elemRowOp()).trace();
}

double Matrix::trace()
{
	using namespace concurrency;
	const int & diag = std::min<int>(_row, _col);
	double trace = 1.0;
	parallel_for(0, diag, [&](int i) {
		trace *= _mat[i][i];
	});
	return trace;
}

Matrix Matrix::getRow(int row_index)const{
	// range check
	if (row_index >= _row || row_index < 0 ) {
		// out of range
		throw new outOfRangeExcep("in Matrix::getRow()");
	}
	return Matrix(_mat[row_index]);
}


Matrix Matrix::getColumn(int col_index)const{
	Matrix ret(_row, 1);
	using namespace concurrency;
	parallel_for(0, _row, [&](int i) {
		ret.set(i, 0, _mat[i][col_index]);
	});
	return ret;
}

void Matrix::setRow(int row_index, const Matrix & m)
{
	if (m.size(0) != 1 || m.size(1) != _col) {
		throw new dimenDismatchExcep(_row, _col, m.size(0), m.size(1));
	}
	if (row_index < 0 || row_index >= _row) {
		throw new invalidParamExcep("invalid row index.");
	}
	copy(m.begin(), m.end(), _mat[row_index].begin());
}

void Matrix::setCol(int col_index, const Matrix & m)
{
	if (m.size(0) != _row || m.size(1) != 1) {
		throw new dimenDismatchExcep(_row, _col, m.size(0), m.size(1));
	}
	if (col_index < 0 || col_index >= _col) {
		throw new invalidParamExcep("invalid column index.");
	}
	using namespace concurrency;
	parallel_for(0, _row, [&](int i) {
		_mat[i][col_index] = m.get(i, 0);
	});
}

void Matrix::removeRow(int index)
{
	if (index < 0 || index >= _row) {
		throw new invalidParamExcep("Invalid row index.");
	}
	// optimize for efficent removal regardless of order
	this->swapRow(index, _row-1);
	_mat.pop_back();
	_row--;
	_begin = Matrix::iterator(_mat.begin(), _mat[0].begin(), _mat[0].size(), _mat.size());
	_end = Matrix::iterator(_mat.end() - 1, (_mat.end() - 1)->end(), _mat[0].size(), _mat.size());
}

void Matrix::removeCol(int index)
{
	if (index < 0 || index >= _col) {
		throw new invalidParamExcep("Invalid column index.");
	}
	// optimize for efficent removal regardless of order.
	using namespace concurrency;
	parallel_for_each(_mat.begin(), _mat.end(), [&](vector<double>& vec) {
		std::swap(vec[index], vec[_col-1]);
		vec.pop_back();
	});
	_col--;
	_begin = Matrix::iterator(_mat.begin(), _mat[0].begin(), _mat[0].size(), _mat.size());
	_end = Matrix::iterator(_mat.end() - 1, (_mat.end() - 1)->end(), _mat[0].size(), _mat.size());
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
	double det;
	if ((det=this->determinant()) == 0.0) {
		// precision problem ? 
		throw new invalidParamExcep("Not a singular matrix.");
	}
	Matrix adj(_row, _col);
	using namespace concurrency;
	parallel_for(0, _row, [&](const int& r) {
		parallel_for(0, _col, [&](const int& c) {
			Matrix m(*this);
			m.removeRow(r);
			m.removeCol(c);
			adj._mat[r][c] = m.determinant();
		});
	});
	return adj.transpose() / det;
}

Matrix Matrix::elemRowOp()
{
	if (_row != _col) {
		throw new dimenDismatchExcep("must be a square matrix.");
	}
	
	if (_row < 2) {
		return *this;
	}
	//int diag_pos = std::min<int>(_row, _col);
	using namespace concurrency;
	Matrix ret(*this);
	for (int k = 0; k < _col-1; k++) {
		parallel_for_each(ret._mat.begin()+k+1, ret._mat.end(), [&](vector<double>& vec) {
			double ratio = vec[k] / ret._mat[k][k];
			parallel_for(0, _row, [&](int j) {
				vec[j] -= ratio * ret._mat[k][j];
			});
		});
	}
	return ret;
}


Matrix Matrix::sum(int sign)const{
	using namespace concurrency;
	if (sign != 0 && sign != 1) {
		// invalid param excep
		throw new invalidParamExcep("in Matrix::sum()");
	}
	Matrix ret;
	if (sign == 0) {
		ret = Matrix(_row, 1);
		parallel_for(0, _row, [&](int i) {
			double result = accumulate(_mat[i].begin(), _mat[i].end(), 0.0);
			ret.set(i, 0, result);
		});
	}
	else if (sign == 1) {
		ret = Matrix(1, _col);
		parallel_for(0, _col, [&](int i) {
			double result = 0.0;
			for (int t = 0; t < _row; t++) {
				result += _mat[t][i];
			}
			ret.set(0, i, result);
		});
	}
	return ret;
}

double Matrix::sum()const{
	using namespace concurrency;
	double ret = 0.0;
	parallel_for_each(_mat.begin(), _mat.end(), [&](vector<double> vec) {
		ret += accumulate(vec.begin(), vec.end(), 0.0);
	});
	return ret;
}


Matrix Matrix::product(int sign){
	using namespace concurrency;
	if (sign != 0 && sign != 1) {
		// invalid param excep
		throw new invalidParamExcep("in Matrix::product()");
	}
	Matrix ret;
	if (sign == 0) {
		ret = Matrix(_row, 1);
		parallel_for(0, _row, [&](int i) {
			double result = accumulate(_mat[i].begin(), _mat[i].end(), 1.0, multiplies<double>());
			ret.set(i, 0, result);
		});
	}
	else if (sign == 1) {
		ret = Matrix(1, _col);
		parallel_for(0, _col, [&](int i) {
			double result = 1.0;
			for (int t = 0; t < _row; t++) {
				result *= _mat[t][i];
			}
			ret.set(0, i, result);
		});
	}
	return ret;
}

double Matrix::product(){
	using namespace concurrency;
	double ret = 1.0;
	parallel_for_each(_mat.begin(), _mat.end(), [&](vector<double> vec) {
		ret *= accumulate(vec.begin(), vec.end(), 1.0, multiplies<double>());
	});
	return ret;
}

Matrix Matrix::max(int sign)const
{
	if (sign != 0 && sign != 1) {
		throw new invalidParamExcep("invalid param in Matrix::max");
	}
	Matrix ret;
	using namespace concurrency;
	if (sign == 1) {
		ret = Matrix(_row, 1);
		parallel_for(0, _row, [&](int i) {
			double d = *(max_element(_mat[i].begin(), _mat[i].end()));
			ret.set(i, 0, d);
		});
	}
	else {
		ret = Matrix(1, _col);
		parallel_for(0, _col, [&](int i) {
			double d = _mat[0][i];
			for (int t = 0; t < _row; t++) {
				d = (_mat[t][i] > d)? _mat[t][i] : d;
			}
			ret.set(0, i, d);
		});
	}
	return ret;
}

Matrix Matrix::min(int sign)const
{
	if (sign != 0 && sign != 1) {
		throw new invalidParamExcep("invalid param in Matrix::max");
	}
	Matrix ret;
	using namespace concurrency;
	if (sign == 1) {
		ret = Matrix(_row, 1);
		parallel_for(0, _row, [&](int i) {
			double d = *(min_element(_mat[i].begin(), _mat[i].end()));
			ret.set(i, 0, d);
		});
	}
	else {
		ret = Matrix(1, _col);
		parallel_for(0, _col, [&](int i) {
			double d = _mat[0][i];
			for (int t = 0; t < _row; t++) {
				d = (_mat[t][i] < d) ? _mat[t][i] : d;
			}
			ret.set(0, i, d);
		});
	}
	return ret;
}

void Matrix::sort(int sign)
{
	if (sign != 0 && sign != 1) {
		throw new invalidParamExcep("invalid param in Matrix::max");
	}
	using namespace concurrency;
	if (sign == 1) {
		parallel_for(0, _row, [&](int i) {
			std::sort(_mat[i].begin(), _mat[i].end());
		});
	}
	else {
		parallel_for(0, _col, [&](int i) {
			vector<double> tmp;
			parallel_for_each(_mat.begin(), _mat.end(), [&](const vector<double>& vec) {
				tmp.push_back(vec[i]);
			});
			parallel_sort(tmp.begin(), tmp.end());
			parallel_for(0, _row, [&](int t) {
				_mat[t][i] = tmp[t];
			});
		});
	}
}

Matrix Matrix::sort(int i) const
{
	Matrix ret(*this);
	ret.sort(i);
	return ret;
}


// Definition of Public Member Functions of the sub-class - Matrix::iterator

Matrix::iterator::iterator(std::vector<std::vector<double> >::iterator& outer, 
	std::vector<double>::iterator& inner, int width, int height){
		this->iter1 = outer;
		this->iter2 = inner;
		this->_width = width;
		this->_height = height;
		this->_step = 0;
		this->_line = 0;
}



Matrix::iterator::iterator():_step(0),_line(0){
}


Matrix::iterator& Matrix::iterator::operator=(const iterator& iter){
	this->iter1 = iter.iter1;
	this->iter2 = iter.iter2;
	this->_width = iter._width;
	this->_height = iter._height;
	this->_line = iter._line;
	this->_step = iter._step;
	return *this;
}

Matrix::iterator Matrix::iterator::operator++(int){
	Matrix::iterator ret(*this);
	if(_step < _width-1){
		iter2++;
		_step++;
	}else if(_line < _height-1){
		iter1++;
		iter2 = iter1->begin();
		_step = 0;
		_line++;
	} else {
		iter2++;
	}
	return ret;
}

Matrix::iterator Matrix::iterator::operator++(){
	if(_step < _width-1){
		iter2++;
		_step++;
	}else if(_line < _height-1){
		iter1++;
		iter2 = iter1->begin();
		_step = 0;
		_line++;
	}
	else {
		iter2++;
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