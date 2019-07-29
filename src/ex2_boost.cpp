#include <boost/math/special_functions/expint.hpp>
#include <iostream>

int main() {
	using namespace boost::math;
	float x = 1.2;
	float y = (-1) * expint(x);
	std :: cout << y << std :: endl;
}
