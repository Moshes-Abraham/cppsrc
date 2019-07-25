#include <iostream>
#include <vector>

int main() {
	std :: vector<int> v;
	int num;
	for (int i = 0; i != 10; ++i){
		if (std :: cin >> num)
			v.push_back(num);
	}

	for (auto it = v.begin(); it != v.end(); ++it){
		std :: cout << (*it) * 2 << std :: endl;
	}
}
