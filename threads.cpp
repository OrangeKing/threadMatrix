#include <iostream>
#include <thread>
#include <chrono>

int glob = 1337;

void foo()
{
	std::this_thread::sleep_for(std::chrono::seconds(4));	//sleep(4);
	std::cout << "foo done" << glob << std::endl;
}

void bar()
{
	std::this_thread::sleep_for(std::chrono::seconds(2));	//sleep(4);
	std::cout << "bar done" << glob << std::endl;
}

int main()
{
	auto fooThread = std::thread(foo); //create new threads
	auto barThread = std::thread(bar); 

	fooThread.join();	//lock till the end of thread
	barThread.join();

	std::cout << "main done" << std::endl;

	return 0;
}
