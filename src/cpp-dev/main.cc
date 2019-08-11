#include "Matrix.hpp"
using namespace std;

int main()
{
	Matrix m(3,4);
	Matrix n(3,4,3);
	ifstream ifs;
	ifs.open("mex.txt");
	ifs >> m;
	ifs.close();
	m = m.multi(n);
	cout << "m = \n" << m << endl;
	Matrix t(4,4,2.3);
	t = t.diag();
	cout << "diag(t) = " << t;
	m = m.T();
	cout << "T(m) = " << m;
	m = m.exponent(3);
	cout << m;	

}
