#include <string>
#include <iostream>
int main() {
	std :: string s("This is a string");
	for (auto &c : s)
		if (c != ' ')
			c = 'X';
	std :: cout << s << std :: endl;
	
	//test
	const std :: string r = "Keep out!";
	for (auto &c : s) {/* ... */};
	std :: cout << r << std :: endl;
}
