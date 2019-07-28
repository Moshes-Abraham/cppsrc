#include <iostream>
#include <vector>

int main() {
	std :: vector<int> array;
	for (int i = 0; i != 100; ++i)
		array.push_back(i);
	// print out
	for (auto i : array) {
		if (i % 6 == 0)
			std :: cout << std :: endl;
		std :: cout << i << "\t";
	}

}
