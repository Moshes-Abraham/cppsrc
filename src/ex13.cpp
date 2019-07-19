#include <iostream>
int main() {
	int i = 0;
	int *ip  = &i;
	//int *p = i;
	std :: cout << ip /*<< "\t" << p */<< std :: endl;
	return 0;
}
