#include <iostream>
#include <thread>
#include <vector>

#include <chrono>
#include <mutex>


std::vector<int> queueFirst;
std::vector<int> queueSecond;	
std::vector<std::vector<int>> matrix;	

std::mutex mx; 

void producerThread()
{
	std::cout << "Foo" << std::endl;
}

void parserThread()
{
	std::cout << "Bar" << std::endl;
}

int main()
{
	std::vector<std::thread> threads;
	for (int i = 0; i < 1; i++)
		threads.push_back(std::thread(producerThread));

	for (int i = 0; i < 1; i++)
		threads.push_back(std::thread(parserThread));

	for (auto& thread : threads)
		thread.join();

	std::cout << "Main Done" << std::endl;
	return 0;
}
