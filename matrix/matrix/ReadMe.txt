=================================================================================
    CONSOLE APPLICATION : Matrix-Computation Project Overview
=================================================================================

===========================Development Instructions=============================

1. Development Environment: 
 IDE: Microsoft Visual Studio 2017.


===============================Code Standards====================================

1. Each method is declared in "mymatrix.h" and implemented in "mymatrix.cpp".
2. Comments of the method in "mymatrix.h" are followed by
 - Simple discription.
 - Input
 - Output
3. add later...

=============================Development Schedule===============================

1. Implement Matrix Class
 1.1 matrix multiply, transpose, spliting, etc
 1.2 reverse, determine
 1.3 optimize matrix operations with iterator
 1.4 exceptions

2. Optimize Matrix I/O
  - file read/write

3. The second class "matlab" provides methods for 
  - generating special matrices: diagonal, unit
  - more element-wise arithmetic operations
  - operations associated with more than two matrices (SVD, eigendecomposition)
  - statistics methods: mean, variance, covariance, etc.

4. The third class "ml" encapsulates machine learning architecture
  - prepocessing 
  - linear/logistic regression
  - shadow neural network


==================================Attention=======================================

1. The Matrix class index from ZERO, not one.
2. The core Matrix elements are stored in vector of vector.
3. Matrix constructors should not support prmitave array (like double[][]) for safety reason.



====================================Help=========================================
1. give up the implementation of const iterator because of additional complexity
which does not bring much convenience. 


/////////////////////////////////////////////////////////////////////////////////
AppWizard has created this matrix application for you.

This file contains a summary of what you will find in each of the files that
make up your matrix application.


matrix.vcxproj
    This is the main project file for VC++ projects generated using an Application Wizard.
    It contains information about the version of Visual C++ that generated the file, and
    information about the platforms, configurations, and project features selected with the
    Application Wizard.

matrix.vcxproj.filters
    This is the filters file for VC++ projects generated using an Application Wizard. 
    It contains information about the association between the files in your project 
    and the filters. This association is used in the IDE to show grouping of files with
    similar extensions under a specific node (for e.g. ".cpp" files are associated with the
    "Source Files" filter).

matrix.cpp
    This is the main application source file.

test.cpp
	This is the test file.

/////////////////////////////////////////////////////////////////////////////
Other standard files:

StdAfx.h, StdAfx.cpp
    These files are used to build a precompiled header (PCH) file
    named matrix.pch and a precompiled types file named StdAfx.obj.

/////////////////////////////////////////////////////////////////////////////
Other notes:

AppWizard uses "TODO:" comments to indicate parts of the source code you
should add to or customize.



Supplimentary Materials:
1. About user-defined iterator. See https://stackoverflow.com/questions/8054273/how-to-implement-an-stl-style-iterator-and-avoid-common-pitfalls.
2. About disable "D_SCL_SECURE_NO_WARNING". See https://stackoverflow.com/a/25046975/7110228.
