#include <iostream>
#include <vector>
#include <boost/math/tools/univariate_statistics.hpp>


int main() {
	std :: vector<double> v{1,2,3,4,5};
	double mu = boost :: math :: tools :: kurtosis(v.cbegin(), v.cend());
	std :: cout << mu << std :: endl;
}
