#include <ncurses.h>
#include <vector>
#include <iostream>
#include <string>

void queueStatus(std::vector<int> first, std::vector<int> second);
void threadStatus(int nProducers, int nParsers);
void board(WINDOW *win, int lines, int cols);
void drawScreen(std::vector<int> first, std::vector<int> second, int nProducers, int nParsers);