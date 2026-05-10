#include <ncurses.h>
#include "./doth/tui.h"

void tui_main(){
	initscr();

	move(5,6);
	printw("test 1");
	mvprintw(20, 40,u8"utf8 test:€");

	refresh();
	getch();
	endwin();
}
