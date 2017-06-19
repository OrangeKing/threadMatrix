#include <ncurses.h>
#include <vector>
#include <iostream>
#include <string>

#define PAWN ACS_DIAMOND

void queueStatus(std::vector<int> first, std::vector<int> second);
void threadStatus(std::vector<int> producers, std::vector<int> parsers); //!! MAKE IT THREAD VEC
void board(WINDOW *win, int lines, int cols);

int main()
{
///////////////////////////////////TEMP VEC DATA///////////////////////////////////
	std::vector<int> cue;
	for (int i = 0; i < 5; i++)
		cue.push_back(5);

	std::vector<int> hue;
	for (int i = 0; i < 8; i++)
		hue.push_back(4);

//////////////////////////////////////////////////////////////////////

	initscr();											//screen 'constructor'
	cbreak();											//raw();
	curs_set(0);										//turnoff cursor

	start_color();										//all colors init
	init_pair(1,COLOR_CYAN, COLOR_BLACK);
	init_pair(2,COLOR_RED, COLOR_BLACK);
	init_pair(3,COLOR_GREEN, COLOR_BLACK);
	init_pair(4,COLOR_WHITE, COLOR_BLACK);

	queueStatus(cue, hue);								//paint info ui
	threadStatus(cue, hue);

    int lines = 5, cols = 5;							//number of rows, number of columns
	WINDOW * win = newwin(100,100,6,3);					//board section window
   	refresh();

   	board(win,lines,cols);								//board painting
	wrefresh(win);

	getch();											//getchar
	endwin();											//screen 'destructor' 

	return 0;
}

void queueStatus(std::vector<int> first, std::vector<int> second)
{
	move(0,0);

	//firstQueue
	attron(COLOR_PAIR(1));
		printw("M coordinates\t");
	attroff(COLOR_PAIR(1));
	
	attron(A_BOLD);
		printw("[  ");
		attron(COLOR_PAIR(2));
			for (int i = 0; i < first.size(); i++)
			{
				printw("%d  ", first[i]);
			}
		attroff(COLOR_PAIR(2));
		printw("]");
	attroff(A_BOLD);

	move(1,0);

	//secondQueue
	attron(COLOR_PAIR(1));
		printw("N coordinates\t");
	attroff(COLOR_PAIR(1));
	
	attron(A_BOLD);
		printw("[  ");
		attron(COLOR_PAIR(2));
			for (int i = 0; i < second.size(); i++)
			{
				printw("%d  ", second[i]);
			}
		attroff(COLOR_PAIR(2));
		printw("]");
	attroff(A_BOLD);
}

void threadStatus(std::vector<int> producers, std::vector<int> parsers)
{
	move(0,100);

	attron(COLOR_PAIR(3));
		printw("Number of producers:  ");
	attroff(COLOR_PAIR(3));
	
	attron(A_BOLD | COLOR_PAIR(4));
		printw("%d",producers.size());
	attroff(A_BOLD | COLOR_PAIR(4));


	move(1,100);

	attron(COLOR_PAIR(3));
		printw("Number of parsers:  ");
	attroff(COLOR_PAIR(3));

	attron(A_BOLD | COLOR_PAIR(4));
		printw("%d",parsers.size());
	attroff(A_BOLD | COLOR_PAIR(4));
}

void board(WINDOW *win, int lines, int cols)
{
	attron(A_UNDERLINE);
    	mvprintw(5,18,"Matrix contents:\n");
    attroff(A_UNDERLINE);

    int tile_height	= 4;							//size of single field
	int tile_width 	= 8;

	int start_x = 0;								//Board drawing (in window) start coords
	int start_y	= 0;

	int end_y, end_x;								//Board drawing (in window) end coords
	end_y = start_y + lines * tile_height;
	end_x = start_x + cols 	* tile_width;

	//Painting the board
	int i,j;

	for(j = start_y; j <= end_y; j += tile_height)				//horizontal lines 
		for(i = start_x; i <= end_x; ++i)
			mvwaddch(win, j, i, ACS_HLINE);
	for(i = start_x; i <= end_x; i += tile_width)				//vertical lines 
		for(j = start_y; j <= end_y; ++j)
			mvwaddch(win, j, i, ACS_VLINE);

	mvwaddch(win,	start_y,	start_x, 	ACS_ULCORNER);		//corner symbols on board endpoints
	mvwaddch(win,	end_y, 		start_x, 	ACS_LLCORNER);
	mvwaddch(win,	start_y,	end_x,		ACS_URCORNER);
	mvwaddch(win,	end_y, 		end_x, 		ACS_LRCORNER);

	for(j = start_y + tile_height; j <= end_y - tile_height; j += tile_height)	//tees on vertical lines
	{
		mvwaddch(win, j, start_x, 	ACS_LTEE);
		mvwaddch(win, j, end_x, 	ACS_RTEE);	

		for(i = start_x + tile_width; i <= end_x - tile_width; i += tile_width)	//pluses on cross-sections
			mvwaddch(win, j, i, ACS_PLUS);
	}

	for(i = start_x + tile_width; i <= end_x - tile_width; i += tile_width)		//tees on horizontal lines
	{
		mvwaddch(win, start_y,	i, 		ACS_TTEE);
		mvwaddch(win, end_y,	i, 		ACS_BTEE);
	}

	//temp : pawn printing
	for(j = start_x + tile_width/2; j <= end_x; j += 8)
		for(i = start_y + tile_height/2; i <= end_y; i += 4)
		{
			mvwaddch(win,i, j, PAWN);
			std::string s = "(" + std::to_string((i-2)/4) + "," + std::to_string((j-4)/8) + ")";

			char const *pchar = s.c_str();
			mvwprintw(win,i, j+1, pchar);
		}
}
