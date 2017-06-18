#include <ncurses.h>
#include <vector>
#include <iostream>

#define PAWN_CHAR ACS_DIAMOND


int main()
{
	std::vector<int> cue;
	for (int i = 0; i < 5; i++)
		cue.push_back(5);

	std::vector<int> hue;
	for (int i = 0; i < 8; i++)
		hue.push_back(4);

///////////////////////////////////NCURSYZ here

	initscr();	//construct
	cbreak();	//raw();
	start_color();

	init_pair(1,COLOR_CYAN, COLOR_BLACK);
	init_pair(2,COLOR_RED, COLOR_BLACK);
	init_pair(3,COLOR_GREEN, COLOR_BLACK);
	init_pair(4,COLOR_WHITE, COLOR_BLACK);



//firstQueue
	attron(COLOR_PAIR(1));
	printw("M coordinates\t");
	attroff(COLOR_PAIR(1));
	attron(A_BOLD);
	printw("[  ");

	attron(COLOR_PAIR(2));
	for (int i=0;i<5;i++)
	{
		printw("%d  ", cue[i]);
	}
	attroff(COLOR_PAIR(2));

	printw("]");
	attroff(A_BOLD);
//end of firstQueue

	move(1,0);

//secondQueue
	attron(COLOR_PAIR(1));
	printw("N coordinates\t");
	attroff(COLOR_PAIR(1));
	attron(A_BOLD);
	printw("[  ");

	attron(COLOR_PAIR(2));
	for (int i=0;i<8;i++)
	{
		printw("%d  ", hue[i]);
	}
	attroff(COLOR_PAIR(2));

	printw("]");
	attroff(A_BOLD);
//end of secondQueue

//Counterz
	move(0,100);
	attron(COLOR_PAIR(3));
	printw("Number of producers:  ");
	attroff(COLOR_PAIR(3));
	attron(A_BOLD);
	attron(COLOR_PAIR(4));
	printw("%d",cue.size());
	attroff(COLOR_PAIR(4));
	attroff(A_BOLD);

	move(1,100);
	attron(COLOR_PAIR(3));
	printw("Number of parsers:  ");
	attroff(COLOR_PAIR(3));
	attron(A_BOLD);
	attron(COLOR_PAIR(4));
	printw("%d",hue.size());
	attroff(COLOR_PAIR(4));
	attroff(A_BOLD);
///////

/////////////////////////////MATRIX////////////////////
int hi = 10;
int wi = 10;

	    int counter, counter2=0;
        curs_set(0);
        attron(A_UNDERLINE);
        mvprintw(5,24,"THE INVENTORY\n");
        attroff(A_UNDERLINE);

			        int height, width, start_y, start_x;
			        height=5;
			       	width = 10;
			       	start_x=start_y=10;

			        WINDOW * win = newwin(5,10, 8,20);
			  		refresh();

			  		box(win,0,0);
			  		mvwaddch(win,2,4, PAWN_CHAR);

			  		
			  		wrefresh(win);

	getch();
	endwin();	//destruct 



	return 0;
}