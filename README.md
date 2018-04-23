
# Matrix-Toolbox

A simple C++ library to help you with matrix computations.

## Demo
To use the library, please `#include "mymatrix.h"`.

### Define a matrix.
Initialize with the number of rows and columns.
```
int row = 10;
int col = 5;
Matrix mat(row, col);
```

Initialize with a row vector of **double**s.
```
vector<double> rowV; 
// ... add elements into rowV
Matrix mat(rowV);
```
Initialize from another matrix.
```
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


