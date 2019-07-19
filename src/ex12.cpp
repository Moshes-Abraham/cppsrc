#include <iostream>
#include <cmath>
int main() {
	int Foo = 0;
	int*pFoo = &Foo;
	int ** ppFoo;
	ppFoo = & pFoo;
	std :: cout << Foo << "\t" << pFoo << "\t" << * pFoo << "\t" << & pFoo 
		 << "\n" << ppFoo << "\t" << *ppFoo << "\t" << &ppFoo
		<< std :: endl << std :: endl ;
	
	int i = 1024;
	int & ref = i;
	// The same as int & ref = & i;
	std :: cout << ref << std :: endl << &ref << std :: endl
		<< *&*& ref << std :: endl ;
	std :: cout << pow(2,8);
	return 0;
}
