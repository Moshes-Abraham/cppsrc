#include <iostream>
int reused = 45;
int main(){
	int unique = 0;
	std :: cout << reused << " " << unique << std :: endl;
	int reused = 0;
	std :: cout << reused << " " << unique << std :: endl;
	std :: cout << ::reused << " " << unique << std :: endl;
	return 0;
}
