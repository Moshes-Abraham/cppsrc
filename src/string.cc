#include <string>
#include <iostream>
int main() {
	//std :: string s1("Shalom, Toda!");
	//std :: string s2(10,'.');
	//std :: cout << s1 << std :: endl << s2 << std :: endl;
	std :: string line;
	getline(std :: cin, line);
	auto len = line.size(); 
	std :: cout << len << std :: endl;
	/*while (getline(std :: cin, line))
		//len = line.size();
		std :: cout << "Hello" << std :: endl;
	return 0;
	*/

}
