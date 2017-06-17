#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include <mutex>

int resourceA = 1000000;
std::mutex resourceAGuard;

int resourceB = 1000000;
std::mutex resourceBGuard;

void foo()
{
	for (int i = 0; i < 100; i++)
	{
		resourceAGuard.lock();
		resourceBGuard.lock();

		resourceA -= 7;
		resourceB += 7;

		//std::cout << "foo" << std::endl;

		resourceBGuard.unlock();
		resourceAGuard.unlock();

	}
}

void bar()
{
	for (int i = 0; i < 100; i++)
	{
		resourceAGuard.lock();
		resourceBGuard.lock();


		resourceA -= 7;
		resourceB += 7;

		//std::cout << "bar" << std::endl;

		resourceBGuard.unlock();
		resourceAGuard.unlock();

	}
}

int main()
{
	auto fooThread = std::thread(foo);
	auto barThread = std::thread(bar);

	fooThread.join();
	barThread.join();

	std::cout << "main done" << std::endl;
	std::cout << "resourceA:" << resourceA << std::endl;
	std::cout << "resourceB:" << resourceB << std::endl;

	return 0;
}
