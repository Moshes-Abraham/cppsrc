#include <iostream>
#include <blaze/Math.h>
using blaze::StaticVector;
using blaze::DynamicVector;

int main() {
	StaticVector<int,3UL> a{ 4, -2, 5};

	DynamicVector<int> b( 3UL );
	b[0] = 2; b[1] = 5; b[2] = -3;

	DynamicVector<int> c = a + b;

	std :: cout << "c = \n" << c << "\n";
}
