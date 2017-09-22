// C++ matrix class
#include <vector>
#include <istream>

class Matrix
{
public:
	Matrix(int row, int col);
	Matrix(const std::vector<double>&);
	~Matrix();
	double get(int row, int col);
	void print();
	void read(std::istream&);
	void append(const std::vector<double>&);

private:
	int _row;
	int _col;
	std::vector<std::vector<double> > _mat;	
};