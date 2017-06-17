#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include <mutex>

int glob = 1337;

long long sum = 0;
std::mutex mx;

void foo()
{
	for (int i = 0; i < 1000000; i++)
	{
		mx.lock();
		sum += 7;
		mx.unlock();
	}
}

void bar()
{
	std::this_thread::sleep_for(std::chrono::seconds(2));	//sleep(4);
	std::cout << "bar done" << glob << std::endl;
}

int main()
{
	std::vector<std::thread> threads;

	//10 watkow FOO
	for (int i = 0; i < 10; i++)
		threads.push_back(std::thread(foo));
	
	for (auto& thread : threads)
		thread.join();

	//auto fooThread = std::thread(foo); //create new threads
	//auto barThread = std::thread(bar); 
	//fooThread.join();	//lock till the end of thread
	//barThread.join();

	std::cout << sum << std::endl;
	std::cout << "main done" << std::endl;

	return 0;
}
