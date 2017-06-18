#include <iostream>
#include <thread>
#include <vector>
#include <random>
#include <chrono>
#include <ncurses.h>
#include <mutex>

#define PAWN_CHAR ACS_DIAMOND

static int RR = 5;
static int CC = 5;
std::vector<std::vector<char>> matrix(RR, std::vector<char>(CC));	//macierz RRxCC (MxN -> 5x5)

std::vector<int> queueFirst;
std::vector<int> queueSecond;	

std::mutex mx; 


void producerThread(int M, int N)
{
	std::random_device rd;
	std::mt19937 mt(rd());

	std::uniform_int_distribution<int> horizontal(0,M-1);	//losowa kolumna
	std::uniform_int_distribution<int> vertical(0,N-1);		// losowy wiersz

	// int first = horizontal(mt);
	// int second = vertical(mt);

	queueFirst.push_back(horizontal(mt));
	queueSecond.push_back(vertical(mt));
}

void parserThread()
{
	//std::this_thread::sleep_for(std::chrono::seconds(2));

	//testy
	matrix[2][2] = 'x';

	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<int> direction(0,3);	//losowy kierunek przesuniecia (0=N;1=S;2=W;3=E)

	for (int i = 0; i < RR; i++)
	{
		for (int j = 0; j < CC; j++)
		{
			if(matrix[i][j]=='x')
			{
				std::cout << "ALARM-" << i+1 << j+1 << std::endl;
				
				matrix[i][j] = 0;
				
				if (j-1>0)
					matrix[i][j-1] = 'x';
			}
		}
	}

	if ((queueFirst.size() > 0) and (queueFirst.size() > 0))
	{
		// std::cout << "First:" << queueFirst.back()+1 << std::endl;
		// std::cout << "Second:" << queueSecond.back()+1 << std::endl;

		matrix[queueFirst.back()][queueSecond.back()] = 'x';

		queueFirst.pop_back();
		queueSecond.pop_back();
	}
}

void nCursesThread()	//wyswietlacz
{
	//std::this_thread::sleep_for(std::chrono::seconds(1));

	for (int i = 0; i < RR; i++)
	{
		for (int j = 0; j < CC; j++)
		{
			std::cout << "Field " << i+1 << "/" << j+1 << ": " << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

int main()
{
	//Background thread running 
	std::vector<std::thread> threads;
	
	for (int i = 0; i < 1; i++)
		threads.push_back(std::thread(producerThread,5,5));	//liczby z zakresu m, n 
	for (int i = 0; i < 1; i++)
		threads.push_back(std::thread(parserThread));

	for (auto& thread : threads)
		thread.join();
	
	//Thread work end here
	// std::cout << "♞" << std::endl;

	std::cout << "Main Done" << std::endl;
	nCursesThread();

	return 0;
}