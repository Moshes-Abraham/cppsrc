#include <iostream>
#define HSIZE 100
#define VSIZE 50

int main() {
	bool Board[HSIZE][VSIZE];
	//for (int i = 0; i <= VSIZE - 1; ++i) {
	//	for (int j = 0; j <= VSIZE - 1; ++j) {
	//		if (i == 0 ) {
	//			Board[i][j] = 1;
	//		} else
	//			Board[i][j] = 0;
	//	}
	//}

	//Print the matrix
	for (int i = 0; i <= VSIZE - 1; ++i) {
		for (int j = 0; j <= HSIZE - 1; ++j) {
			if (Board[i][j] == 1)
				std :: cout << "o";
			else
				std :: cout << ".";
		}
		//head to the next raw
		std :: cout << std :: endl;

	}
}



