#include <iostream>
#include <numeric>
#include <vector>


int main()
{
	std :: vector<int> a{0, 1, 2, 3, 4};
	std :: vector<int> b{5, 4, 3, 2, 1};

	int r1 = std :: inner_product(a.begin(), a.end(), b.begin(), 0);
	std :: cout << "The inner product between a and b is " << r1 << std :: endl;
}
