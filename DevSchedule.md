
## Development Environment
 IDE: Microsoft Visual Studio 2017.
 Require C++ 11

## Development Schedule
1. Implement Matrix Class
  - Mostly done.

2. The second class "matlab" provides methods for 
  - operations associated with more than two matrices.
  - statistics methods: variance, covariance, etc. 


### Optimization items:
- matrix operations with iterator & parallelism
- exceptions handling optimization
- file read/write
- more element-wise arithmetic operations
- elementary row operation in case of rounding error

5. Documentation 

### Pitfalls
1. Be extremely careful about any operation of `_mat` that may **invalidate** Matrix::iterator.
`_mat` must keep its iterators stable with any computation except construction(including row/col editing).

### Attention
1. The Matrix class index from ZERO, not one.
2. The core Matrix elements are stored in vector of vector.
3. Matrix constructors should not support prmitave array (like double[][]) for safety reason.


### Files
- matrix.cpp
  
  The entry of the application.

- mymatrix.h
  
  The definition of matrix class.

- specialmat.h
	
	Some special matrices that inherite the base Matrix class.

- matlab.h
  
  The definition of matlab class.

- exception.h 
  
  The definition of Matrix related exception classes.

- ml.h

	(future development) The definition of encapsulation of machine learning algorithm. 

- test.cpp

	The test file.

- stdafx.h targetver.h
	
	Additional file required by Visual Studio.



### Supplimentary Materials:
1. About user-defined iterator. See https://stackoverflow.com/questions/8054273/how-to-implement-an-stl-style-iterator-and-avoid-common-pitfalls.
2. About disable "D_SCL_SECURE_NO_WARNING". See https://stackoverflow.com/a/25046975/7110228.
3. C++11 random number generator. See https://stackoverflow.com/a/19666713/7110228.


## Inverse Matrix: Gauss-Jordon Method

```
for k=1:n
	A[k][k] = 1 / A[k][k]
	for i=1:n and i!=k
		A[i][k] = - A[i][k] / A[k][k]
	end

	for i=1:n, j=1:n, i!=k, j!=k
		A[i][j] = A[i][j] + A[i][k] * A[k][j]
	end

	for j=1:n, j!=k
		A[k][j] = A[k][k] * A[k][j]
	end
end
```


## Iterative method for solving linear equations

## power method for solving eigen-vectors and eigen-values

