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
	start_color();
	init_color(11,555,256,0);
	init_color(12,555,555,20);
	init_color(12,type_page.color_correct.bg.r
			,type_page.color_correct.bg.g
			,type_page.color_correct.bg.b);

	init_pair(11,11,12);

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

	mvwprintw(challange_space_win,2,1,"qwre cs:%d c:%d",COLOR_PAIRS,COLORS);
	char* test_str="asgvaerhaethbtbhtrhh";
	gb_init(test_str, (int)strlen(test_str), 256);
	mvwprintw(challange_space_win,1,1,"%s",test_str);
	wmove(challange_space_win, 1,1);
	wmove(type_space_win, 1,1);
	wrefresh(challange_space_win);
	wrefresh(type_space_win);

	int ch=0;
	while(1){
		char* str;
		char* status;
		gb_get_status(&str, &status);

		wclear(type_space_win);
		box(type_space_win,0,0);
	wattron(type_space_win,COLOR_PAIR(11));
		wmove(type_space_win,1,1);

		int i=0,x=-1,y=-1;
		while(str[i]){
			if(status[i]=='u'&& x==-1&& y==-1){
				x=getcurx(type_space_win);
				y=getcury(type_space_win);
			}

			waddch(type_space_win,(chtype)str[i]);
			if(getcurx(type_space_win)+1==getmaxx(type_space_win))
				wmove(type_space_win,getcury(type_space_win)+1,1);
			++i;
		}
		if(!(x==-1 || y==-1))
			wmove(type_space_win,y,x);
		free(str);free(status);
	wattroff(type_space_win,COLOR_PAIR(11));

		curs_set(0); wrefresh(type_space_win); curs_set(1);

		/* input processing */
		ch=wgetch(type_space_win);
		switch(ch){
			case KEY_BACKSPACE: case KEY_DC: case 127: /*BS ascii*/ case 8:
				gb_pop();
			break; case 27: /*escape*/ case '\n':
				goto exit;
			break; default:
				gb_push((char)ch);
		}
	}
	exit:
	delwin(challange_space_win);
	delwin(type_space_win);
	endwin();
}

