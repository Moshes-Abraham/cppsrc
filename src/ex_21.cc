#include <iostream>
#include <string>
#include <vector>
int main() {

	std :: vector<char> text;
	char c;
	while (std :: cin >> c) {
		text.push_back(c);
	}

	for (auto it = text.cbegin();
			it != text.cend() && !it -> empty(); ++it)
		std :: cout << *it << std :: endl;
}
