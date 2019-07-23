#include <iostream>
int main() {
	int num = 0;
	int *const pnum = &num;
	const double Pi = 3.1415;
	const double *const pPi = &Pi;
	std :: cout << "pnum: " << pnum << "\n"
		<< "pPi: " << pPi << std :: endl;

	pnum = 0;   //compiling error here!
	std :: cout << "pnum: " << pnum << "\n"
		<< "pPi: " << pPi << std :: endl;
	return 0;
}
