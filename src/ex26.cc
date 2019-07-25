#include <iostream>

int main() {
	constexpr size_t array_size = 10;
	int ay[array_size];
	for (int i = 0; i != 10; ++i) {
		ay[i] = i;
	}

	for (auto id : ay) {
		std :: cout << ay[id] << std :: endl;
	}
}
