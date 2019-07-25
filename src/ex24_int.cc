#include <iostream>
#include <vector>
using std::vector;

int main () {
	vector<int> v;
	int num;
	while (std :: cin >> num) {
		v.push_back(num);
	}

	for (auto i = v.begin(); i != v.end() - 1; ++i) {
		std :: cout << *i + *(i+1) << std :: endl;
	}
}
