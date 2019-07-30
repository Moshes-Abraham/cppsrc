#include <iostream>
#include <cstdlib>
#include <boost/thread/thread.hpp>

volatile bool isRuning = true;
void func1()
{
	static int cnt1 = 0;
	while (isRuning)
	{
		std :: cout << "func1:" << cnt1++ << std :: endl;
		sleep(1);
	}
}

void func2()
{
	static int cnt2 = 0;
	while (isRuning)
	{
		std :: cout << "func2:" << cnt2++ << std :: endl;
		sleep(2);
	}
}

int main() {
	boost::thread thread1(&func1);
	boost::thread thread2(&func2);
	system("read");
	isRuning = true;
	thread2.join();
	thread1.join();
	std :: cout << "exit" << std :: endl;
	return 0;
}

