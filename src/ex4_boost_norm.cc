#include <vector>
#include <iostream>
#include <boost/math/tools/norms.hpp>

int main() {
	std :: vector<double> v{8, 0, 0};
	double sup = boost::math::tools::lp_norm(v.cbegin(), v.cend(), 7);
	std :: cout << sup << std :: endl;

	std::vector<std::complex<double>> r{{1, 0}, {0, 1}, {0, -1}};
	double lp = boost::math::tools::lp_norm(r.cbegin(), r.cend(), 3);
	std :: cout << lp << std :: endl;
}
