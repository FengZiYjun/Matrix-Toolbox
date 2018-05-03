
# Matrix-Toolbox

A simple C++ library to help you with matrix computations.

## Documentation
To use the library, please `#include "mymatrix.h"`.

### Define a matrix.
Initialize with the number of rows and columns.
```C++
int row = 10;
int col = 5;
Matrix mat(row, col);
```

Initialize with a row vector of **double**s.
```C++
vector<double> rowV; 
// ... add elements into rowV
Matrix mat(rowV);
```
Initialize from another matrix.
```C++
Matrix matA(mat);
```

### Basic Operations
#### 1. get the size of the matrix
`mat.size(0)` returns the number of rows.

`mat.size(1)` returns the number of columns.

#### 2. access an element
**Notice**: Matrix index starts from ZERO.

`double x = mat.get(0, 1);`
`mat.set(0, 1, x);`

#### 3. convert into vector of vectors

`vector<vector<double> > V = mat.toVector();`

#### 4. Row/Column Operations

Access the i-th row. (0 <= i < #rows)
```C++
Matrix r = mat.getRow(i);
```

Access the j-th column. (0 <= j < #col)
```C++
Matrix c = mat.getColumn(j);
```

Modify the i-th row.
```C++
Matrix new_row(mat.size(0), 1);
// add elements into new_row
mat.setRow(i, new_mat);
```

Modify the j-th column.
```C++
Matrix new_col(1, mat.size(1));
// add elements into new_row
mat.setCol(j, new_mat);
```

Add new rows under the last row. 

The `appendRow` member function takes a `vector<double>` or a `Matrix` with the same number of columns as parameter.
```C++
mat.appendRow(rowV); 
mat.appendRow(new_mat);
```

Add new columns after the last column. 
```C++
mat.appendCol(rowV); 
mat.appendCol(new_mat);
```
`new_mat` must have the same number of rows.

Swap two rows.
```C++
// swap the first and second row
mat.swap(0, 1); 
```

#### 5. Splitting
Horizontal split over a matrix indicated by its column index.
```C++
vector<int> vec;
vec.push_back(0);
vec.push_back(2);
vector<Matrix> split_mats = mat.hsplit(vec);
//split_mats[0] is the first column of mat
//split_mats[1] is the third column of mat
```

Split all columns. Pass no parameters.
```C++
vector<Matrix> split_mats = mat.hsplit();
```

The same to vertical splitting, with `vspilt` and row index as parameters.

To split all rows, pass no parameters.

#### 6. Simple computation
**overloaded operators**

Matrix & Matrix
```C++
Matrix matA;
Matrix matB;
// ... initialization
Matrix result;
result = matA + matB; // addition
result = matA - matB; // subtraction
result = matA * matB; // matrix multiply. matA column number == matB row number

bool equal = (matA == matB);
bool noneq = (matA != matB);
```

Matrix & scalar
```C++
result = matA * 0.01; // element-wise multiply
result = 0.01 * matA;
result = matA / 2;	// element-wise division
```


**Notice**: 0 means row operations. 1 means column operations.

Sum up elements along rows.
```C++
Matrix sum = mat.sum(0);
```

Sum  up elements along columns.
```C++
Matrix sum = mat.sum(1);
```

The same to `product`, `max`, and `min`.

Elements multiplication, maximum or minimum element along rows/columns, respectively.

Sum up all matrix elements.
```C++
double sum = mat.sum();
```

Multipliy all matrix elements.
```C++
double product = mat.product();
```

Get the mean of each row or column with `mean`.

Get the variance of each row or column with `variance`.

Sort rows or columns with `sort`.


#### 7. Linear algebra
