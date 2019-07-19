#include <iostream>
int main(){
	int num1, num2, temp;
	std :: cin >> num1 >> num2;
	if (num1 > num2){
		temp = num1;
		num1 = num2;
		num2 = temp;
	}
	while (num2 >= num1){
		std :: cout << num2 << std :: endl;
		--num2;
	}
	return 0;
}
