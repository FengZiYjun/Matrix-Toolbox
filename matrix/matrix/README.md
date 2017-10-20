
# Matrix-Toolbox Project Overview

## Development Environment
 IDE: Microsoft Visual Studio 2017.
 Require C++ 11

## Development Schedule
1. Implement Matrix Class
 - inverse (waiting-hard)
 (Inversion needs to decide whether a matrix is singular. This needs 
 elementary row operation to transform the matrix into echelon form or 
 computation of determinant. Also, MP-inversion needs to solve a matrix 
 equation.)
 - solve, rank

2. The second class "matlab" provides methods for 
  - operations associated with more than two matrices (SVD, eigendecomposition) (waiting-hard)
  - statistics methods: mean, variance, covariance, etc. (undergoing)

3. The third class "ml" encapsulates machine learning architecture
  - prepocessing 
  - linear/logistic regression (undergoing)
  - shadow neural network

### Optimization items:
- matrix operations with iterator & parallelism
- exceptions handling optimization
- file read/write
- more element-wise arithmetic operations
- elementary row operation in case of rounding error

5. Documentation 


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

	The definition of encapsulation of machine learning algorithm.

- test.cpp

	The test file.

- stdafx.h targetver.h
	
	Additional file required by Visual Studio.



### Supplimentary Materials:
1. About user-defined iterator. See https://stackoverflow.com/questions/8054273/how-to-implement-an-stl-style-iterator-and-avoid-common-pitfalls.
2. About disable "D_SCL_SECURE_NO_WARNING". See https://stackoverflow.com/a/25046975/7110228.
3. C++11 random number generator. See https://stackoverflow.com/a/19666713/7110228.