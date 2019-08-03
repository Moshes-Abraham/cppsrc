#include <iostream>
#include <ostream>

template<class T>
T absval(T x)
{
	if (x < 0)
		return -x;
	else
		return x;
}

int main()
{
	std :: cout << absval(-42) << std :: endl;
	std :: cout << absval(-4.2) << std :: endl;
	std :: cout << absval(4.2) << std :: endl;
	std :: cout << absval(-42L) << std :: endl;
	std :: cout << absval(42) << std :: endl;
}
