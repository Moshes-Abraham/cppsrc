#include "Sales_item.h"
int main() {
	Sales_item total;	// store variable for the next one
	// read the first data, make sure there are data to proceed
	if (std :: cin >> total) {
		Sales_item trans;	// variable for storing the sum
		// read and proceed the else records
		while (std :: cin >> trans ) {
				if (total.isbn == trans.isbn)
					total += trans;
				else {
					std :: cout << total << std :: endl;
					total = trans;
				}

			}
		std :: cout << total << std :: endl;
	} else {
		std :: cerr << "No data?!" << std :: endl;
		return -1;
	}
	return 0;
}
