#include <iostream>
#include <vector>

int main() {
	std :: vector<int> ivec(10,1);
	for (auto i : ivec)
		std :: cout << i << std :: endl;
	std :: cout << std :: endl;

	std :: vector<int>:: size_type cnt = ivec.size();
	//
	for (std::vector<int>::size_type ix = 0;
			ix != ivec.size(); ++ix, --cnt) // the comma is here
		ivec[ix] = cnt;

	for (auto i : ivec)
		std :: cout << i << std :: endl;
	std :: cout << std :: endl;
}
