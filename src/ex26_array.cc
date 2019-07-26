#include <iostream>

int main() {
	int ia[] = {0,1,2,3,4,5,6,7,8,9};
	int *beg = std :: begin(ia);
	int *last = std :: end(ia) - 1;
	std :: cout << "The first eleement of ia: " << *beg << std :: endl;
	std :: cout << "The last eleement of ia: " << *last << std :: endl;
}
