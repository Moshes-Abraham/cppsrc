#include <iostream>
#include <string>
#include <vector>
int main() {

	std :: vector<std :: string> text;
	std :: string c;
	unsigned capacity = 0;
	while (std :: cin >> c) {   // use <ctrl>d to jump out this loop
		text.push_back(c);
	}

	for (auto it = text.cbegin();
			it != text.cend() && !it -> empty(); ++it){
		std :: cout << *it << std :: endl;
		capacity += 1;
	}
	std :: cout << capacity << std :: endl;
}
