#include <iostream>
#include <boost/progress.hpp>

int main() {
	vector<string> v(100, "aaa");

	v[10] = ""; v[23] = "";
	ofstream fs("./test.txt");
	progress_display pd(v.size());

	for (auto pos = v.begin(); pos != v.end(); ++pos)
	{
		fs << *pos << endl;
		++pd;
		if (pos -> empty())
		{
			cout << "null string # "
				<< (pos - v.begin()) << endl;
		}
	}
}
