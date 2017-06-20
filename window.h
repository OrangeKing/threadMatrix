#include <ncurses.h>
#include <iostream>
#include <vector>
#include <string>

void queueStatus(std::vector<int> first, std::vector<int> second);
void threadStatus(int nProducers, int nParsers);
void board(WINDOW *win, int lines, int cols, std::vector<std::vector<char>>matrix);
void drawScreen(std::vector<int> first, std::vector<int> second, int nProducers,
	int nParsers,int M, int N, std::vector<std::vector<char>>matrix);


void shiftRight(std::vector<std::vector<char>>	&values);
void shiftLeft(std::vector<std::vector<char>>	&values);
void shiftUp(std::vector<std::vector<char>>		&values);
void shiftDown(std::vector<std::vector<char>> 	&values);
