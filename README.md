
# Matrix-Toolbox

A simple C++ library to help you with matrix computations.

## Demo
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
1. get the size of the matrix
`mat.size(0)` returns the number of rows.
`mat.size(1)` returns the number of columns.

2. access an element
**Notice**: Matrix index starts from ZERO.

`double x = mat.get(0, 1);`
`mat.set(0, 1, x);`

3. convert into vector of vectors
`vector<vector<double> > V = mat.toVector();`

4. Row/Column Operations
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

