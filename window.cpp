#include "window.h"

#define PAWN ACS_DIAMOND

void drawScreen(std::vector<int> first, std::vector<int> second, int nProducers, 
	int nParsers,int M, int N, std::vector<std::vector<char>>matrix)
{
	int c = 0;											//time iterator
    int lines = M, cols = N;							//number of rows, number of columns

	initscr();											//screen 'constructor'
	cbreak();											//raw();
	curs_set(0);										//turnoff cursor

	start_color();										//all colors init
	init_pair(1,COLOR_CYAN, COLOR_BLACK);
	init_pair(2,COLOR_RED, COLOR_BLACK);
	init_pair(3,COLOR_GREEN, COLOR_BLACK);
	init_pair(4,COLOR_WHITE, COLOR_BLACK);

	while(c < 5)
	{
		clear();
		queueStatus(first, second);							//paint info ui
		threadStatus(nProducers, nParsers);
		WINDOW * win = newwin(100,100,6,3);					//board section window

   		board(win,lines,cols,matrix);						//board painting
   		mvprintw(0,50,"%d",c);
   		refresh();
		wrefresh(win);

		c++;
		usleep(1000000);
	}

	//getch();											//getchar
	endwin();											//screen 'destructor' 
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

void threadStatus(int nProducers, int nParsers)
{
	move(0,100);

	attron(COLOR_PAIR(3));
		printw("Number of producers:  ");
	attroff(COLOR_PAIR(3));
	
	attron(A_BOLD | COLOR_PAIR(4));
		printw("%d",nProducers);
	attroff(A_BOLD | COLOR_PAIR(4));

	move(1,100);

	attron(COLOR_PAIR(3));
		printw("Number of parsers:  ");
	attroff(COLOR_PAIR(3));

	attron(A_BOLD | COLOR_PAIR(4));
		printw("%d",nParsers);
	attroff(A_BOLD | COLOR_PAIR(4));
}

void board(WINDOW *win, int lines, int cols, std::vector<std::vector<char>>matrix)
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

	//pawn printing
	for(j = start_x + tile_width/2; j <= end_x; j += 8)
		for(i = start_y + tile_height/2; i <= end_y; i += 4)
		{
			if(matrix[(i-2)/4][(j-4)/8]=='x')
				mvwaddch(win,i, j, PAWN);

			std::string s = "(" + std::to_string((i-2)/4) + "," + std::to_string((j-4)/8) + ")";
			char const *pchar = s.c_str();
			mvwprintw(win,i+2, j, pchar);
		}
}
