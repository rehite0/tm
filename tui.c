#include <ncurses.h>
#include <unistd.h>
#include "./doth/tui.h"

void tui_main(){
	initscr();
	noecho();
	cbreak();

	WINDOW* challange_space_win= newwin(
			type_page.challenge_space.h
			, type_page.challenge_space.w
			, type_page.challenge_space.y
			, type_page.challenge_space.x);

	WINDOW* type_space_win= newwin(
			type_page.type_space.h
			, type_page.type_space.w
			, type_page.type_space.y
			, type_page.type_space.x);
	refresh();
	
	box(challange_space_win,0,0);
	box(type_space_win,0,0);

	mvwprintw(challange_space_win,1,1,"asd");
	mvwprintw(type_space_win,1,1,"qwre");
	wrefresh(challange_space_win);
	wrefresh(type_space_win);

	int ch=0;
	while( (ch=getch()) ){
		wprintw(type_space_win,"%c",ch);
		if(getcurx(type_space_win)+1==getmaxx(type_space_win))
			wmove(type_space_win,getcury(type_space_win)+1,1);
		wrefresh(type_space_win);
	}
	napms(1000);
	delwin(challange_space_win);
	delwin(type_space_win);
	endwin();
}

