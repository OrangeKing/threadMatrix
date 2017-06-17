#include <iostream>
#include <thread>
#include <vector>
#include <random>

#include <chrono>
#include <mutex>

std::vector<int> queueFirst;
std::vector<int> queueSecond;	

std::mutex mx; 

std::vector<std::vector<int>> matrix;	

void producerThread(int M, int N)
{
	std::random_device rd;
	std::mt19937 mt(rd());

	std::uniform_int_distribution<int> horizontal(0,M-1);
	std::uniform_int_distribution<int> vertical(0,N-1);

	int first = horizontal(mt);
	int second = vertical(mt);

	queueFirst.push_back(horizontal(mt));
	queueSecond.push_back(vertical(mt));
}

void parserThread()
{
	std::cout << "First:" << queueFirst.back() << std::endl;
	queueFirst.pop_back();
	std::cout << "Second:" << queueSecond.back() << std::endl;
	queueSecond.pop_back();
}

int main()
{
	std::vector<std::thread> threads;
	for (int i = 0; i < 2; i++)
		threads.push_back(std::thread(producerThread,10,3));

	for (int i = 0; i < 1; i++)
		threads.push_back(std::thread(parserThread));


	for (auto& thread : threads)
		thread.join();

	std::cout << "Main Done" << std::endl;
	char symbol = 254;
	int a = symbol;
	std::cout << "♞" << std::endl;
	return 0;
}