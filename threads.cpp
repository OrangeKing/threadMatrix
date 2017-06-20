#include <thread>
#include <mutex>
#include <random>
#include <chrono>

#include "window.h"

static int RR = 6;						//rows 		(Ms)
static int CC = 6;						//columns 	(Ns)

std::vector<std::vector<char>> matrix(RR, std::vector<char>(CC));	//matrix RRxCC (MxN -> 5x5)

std::vector<int> queueFirst;
std::vector<int> queueSecond;	

std::mutex mx; 

void producerThread(int M, int N)
{
	std::random_device rd;
	std::mt19937 mt(rd());

	std::uniform_int_distribution<int> horizontal(0,M-1);	//random row
	std::uniform_int_distribution<int> vertical(0,N-1);		//random column

	mx.lock();
		queueFirst.push_back(horizontal(mt));
		queueSecond.push_back(vertical(mt));
	mx.unlock();
}

void parserThread()
{
	std::this_thread::sleep_for(std::chrono::seconds(2));

	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<int> direction(0,3);	//random shuffle (0=N;1=S;2=W;3=E)

	int pick = direction(mt);

	switch(pick)
	{
		case 0 : 
			shiftUp(matrix);
			break;
		case 1 : 
			shiftLeft(matrix);
			break;
		case 2 : 
			shiftDown(matrix);
			break;
		case 3 : 
			shiftRight(matrix);
			break;
		default:
			break;
	}

	//retrive pawn
	mx.lock();
	if ((queueFirst.size() > 0) and (queueFirst.size() > 0))
	{
		matrix[queueFirst.back()][queueSecond.back()] = 'x';
		queueFirst.pop_back();
		queueSecond.pop_back();
	}
	mx.unlock();
}

int main()
{
	//Background threads running 
	std::vector<std::thread> producerThreads;
	std::vector<std::thread> parserThreads;

	for (int i = 0; i < 3; i++)
		producerThreads.push_back(std::thread(producerThread,RR,CC));	
	for (int i = 0; i < 1; i++)
		parserThreads.push_back(std::thread(parserThread));
	
	auto screenThread = std::thread(drawScreen,queueFirst,queueSecond,producerThreads.size(),parserThreads.size(),RR,CC,matrix);
	
	for (auto& thread : producerThreads)
		thread.join();
	for (auto& thread : parserThreads)
		thread.join();

	screenThread.join();

	std::cout << "Main Done" << std::endl;
	return 0;
}