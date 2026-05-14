#include <ncurses.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "./doth/tui.h"
#include "./doth/utils.h"
#include "./doth/core.h"

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

	// mvwprintw(type_space_win,1,1,"qwre");
	char* test_str="asgvaerhaethbtbhtrhh";
	gb_init(test_str, (int)strlen(test_str), 256);
	mvwprintw(challange_space_win,1,1,"%s",test_str);
	wmove(challange_space_win, 1,1);
	wmove(type_space_win, 1,1);
	wrefresh(challange_space_win);
	wrefresh(type_space_win);

	int ch=0;
	while( (ch=wgetch(type_space_win)) ){
		switch(ch){
			case KEY_BACKSPACE: case KEY_DC: case 127: case 8:
				gb_pop();

			break; case 27: //escape
				goto exit;
			break; default:
				gb_push((char)ch);
		}
		char* str;
		char* status;
		gb_get_status(&str, &status);

		wclear(type_space_win);
		box(type_space_win,0,0);
		wmove(type_space_win,1,1);

		int i=0;
		while(str[i]){
			wprintw(type_space_win,"%c",str[i]);
			if(getcurx(type_space_win)+1==getmaxx(type_space_win))
				wmove(type_space_win,getcury(type_space_win)+1,1);
			++i;
		}
		free(str);free(status);
		curs_set(0);
		wrefresh(type_space_win);
		curs_set(1);
	}
	exit:
	delwin(challange_space_win);
	delwin(type_space_win);
	endwin();
}

