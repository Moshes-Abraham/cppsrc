#include <iostream>

int main() {
	unsigned int grade = 0;
	while (std :: cin >> grade) {
		std :: string finalgrade = (grade > 90) ? "high pass"
			: (grade < 60) ? "fail" : "pass";
		std :: cout << finalgrade << std :: endl;
	}
}
