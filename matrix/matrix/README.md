
# Matrix-Toolbox Project Overview

## Development Environment
 IDE: Microsoft Visual Studio 2017.

## Development Schedule
1. Implement Matrix Class (mostly done)
 - inverse, determine (waiting)
 - optimize matrix operations with iterator & parallelism (needs optimization)
 - exceptions handling optimization (needs optimization)

2. Optimize Matrix I/O (done)
  - file read/write (needs optimization)

3. The second class "matlab" provides methods for 
  - more element-wise arithmetic operations  (needs optimization)
  - operations associated with more than two matrices (SVD, eigendecomposition) (waiting)
  - statistics methods: mean, variance, covariance, etc. (undergoing)

4. The third class "ml" encapsulates machine learning architecture (waiting)
  - prepocessing 
  - linear/logistic regression
  - shadow neural network

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