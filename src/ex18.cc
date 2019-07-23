#include <string>
#include <iostream>
using std :: string;
int main() {
	string s("some string");
	for (auto &c : s)
		c = toupper(c);
	std :: cout << s << std :: endl;
	if (!s.empty())
		s[0] = tolower(s[0]);
	std :: cout << s << std :: endl;
}
