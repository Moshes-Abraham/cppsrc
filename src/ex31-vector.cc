#include <iostream>
#include <vector>

int main() {
	std :: vector<std :: vector<int>> level = 	{{1,2,3,4},
							{2,3,4,5},
							{3,4,5,6},
							{4,5,6,7}};
	for (auto i : level) {
		for (auto j : i)
			std :: cout << j;
		std :: cout << std :: endl;
	}

  std :: cout << "Good afternoon, yosh." << std :: endl;
}
