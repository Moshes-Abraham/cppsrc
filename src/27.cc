#include <iostream>
#include <vector>
using std :: vector;

int main() {
	// initialize a 5x3 array
	vector<vector<int> > r(5);
	for (auto it = r.begin(); it != r.end(); ++it) {
		it -> resize(3);   // it can also be expressed as: (*it).resize(3);
	}
	
	r[0][0] = 1; r[0][1] = 1; r[0][2] = 1;
	r[1][0] = 2; r[1][1] = 1; r[1][2] = 2;
	r[2][0] = 3; r[2][1] = 1; r[2][2] = 3;
	r[3][0] = 4; r[3][1] = 1; r[3][2] = 4;
	r[4][0] = 5; r[4][1] = 1; r[4][2] = 5;

	for (auto itr = r.begin(); itr != r.end(); ++itr) {
		//for (auto itc = (*itr).begin() ; itc != (*itr).end(); ++itc) {
		for (auto itc = itr -> begin() ; itc != itr -> end(); ++itc) {
			std :: cout << *itc << "\t";
		}
		std :: cout << std :: endl;
	}

	// I can change the size of the 5x3 array to 5x4 array dynamically

	for (auto it = r.begin(); it != r.end(); ++it) {
		it -> resize(4);   // it can also be expressed as: (*it).resize(3);
	}

	r[0][0] = 1; r[0][1] = 1; r[0][2] = 1; r[0][3] = 1;
	r[1][0] = 2; r[1][1] = 1; r[1][2] = 2; r[1][3] = 2;
	r[2][0] = 3; r[2][1] = 1; r[2][2] = 3; r[2][3] = 3;
	r[3][0] = 4; r[3][1] = 1; r[3][2] = 4; r[3][3] = 4;
	r[4][0] = 5; r[4][1] = 1; r[4][2] = 5; r[4][3] = 5;


	for (auto itr = r.begin(); itr != r.end(); ++itr) {
		//for (auto itc = (*itr).begin() ; itc != (*itr).end(); ++itc) {
		for (auto itc = itr -> begin() ; itc != itr -> end(); ++itc) {
			std :: cout << *itc << "\t";
		}
		std :: cout << std :: endl;
	}



}
