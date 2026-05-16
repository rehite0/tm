#include <ncurses.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "./doth/tui.h"
#include "./doth/utils.h"
#include "./doth/core.h"

static void color_fill();
static void set_uptui();
static void set_uptui(){
	initscr();
	noecho();
	cbreak();
	start_color();
	color_fill();
	init_color(11,type_page.color_correct.fg.r
			,type_page.color_correct.fg.g
			,type_page.color_correct.fg.b);
	init_color(12,type_page.color_correct.bg.r
			,type_page.color_correct.bg.g
			,type_page.color_correct.bg.b);
	init_pair(11,11,12); /* correct color */

	init_color(13,type_page.color_wrong.fg.r
			,type_page.color_wrong.fg.g
			,type_page.color_wrong.fg.b);
	init_color(14,type_page.color_wrong.bg.r
			,type_page.color_wrong.bg.g
			,type_page.color_wrong.bg.b);
	init_pair(12,13,14); /* wrong color */

	init_color(15,type_page.color_untyped.fg.r
			,type_page.color_untyped.fg.g
			,type_page.color_untyped.fg.b);
	init_color(16,type_page.color_untyped.bg.r
			,type_page.color_untyped.bg.g
			,type_page.color_untyped.bg.b);
	init_pair(13,15,16); /* untyped color */

	init_color(17,type_page.type_space.color_border.fg.r
			,type_page.type_space.color_border.fg.g
			,type_page.type_space.color_border.fg.b);
	init_color(18,type_page.type_space.color_border.bg.r
			,type_page.type_space.color_border.bg.g
			,type_page.type_space.color_border.bg.b);
	init_pair(14,17,18); /* type space border color */

	init_color(19,type_page.challenge_space.color_border.fg.r
			,type_page.challenge_space.color_border.fg.g
			,type_page.challenge_space.color_border.fg.b);
	init_color(20,type_page.challenge_space.color_border.bg.r
			,type_page.challenge_space.color_border.bg.g
			,type_page.challenge_space.color_border.bg.b);
	init_pair(15,19,20); /* challenge space border color */

	init_color(21,type_page.type_space.color.fg.r
			,type_page.type_space.color.fg.g
			,type_page.type_space.color.fg.b);
	init_color(22,type_page.type_space.color.bg.r
			,type_page.type_space.color.bg.g
			,type_page.type_space.color.bg.b);
	init_pair(16,21,22); /* type space color */

	init_color(23,type_page.challenge_space.color.fg.r
			,type_page.challenge_space.color.fg.g
			,type_page.challenge_space.color.fg.b);
	init_color(24,type_page.challenge_space.color.bg.r
			,type_page.challenge_space.color.bg.g
			,type_page.challenge_space.color.bg.b);
	init_pair(17,23,24); /* challenge space color */

	init_color(25,type_page.color_page.fg.r
			,type_page.color_page.fg.g
			,type_page.color_page.fg.b);
	init_color(26,type_page.color_page.bg.r
			,type_page.color_page.bg.g
			,type_page.color_page.bg.b);
	init_pair(18,25,26); /* type page color */
}

void tui_main(){
	set_uptui();
	bkgd(COLOR_PAIR(18));

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
	
	wbkgd(type_space_win,COLOR_PAIR(16));
	wbkgd(challange_space_win,COLOR_PAIR(17));
	
	wattron(challange_space_win,COLOR_PAIR(15));
	box(challange_space_win,0,0);
	wattroff(challange_space_win,COLOR_PAIR(15));

	char* test_str="quick brown fox jump over the lazy brown dog";
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
		wattron(type_space_win,COLOR_PAIR(14));
		box(type_space_win,0,0);
		wattroff(type_space_win,COLOR_PAIR(14));
		wmove(type_space_win,1,1);

		int i=0,x=-1,y=-1;
		while(str[i]){
			if(status[i]=='u'&& x==-1&& y==-1){
				x=getcurx(type_space_win);
				y=getcury(type_space_win);
			}

			if(status[i]=='c')	 wattron(type_space_win,COLOR_PAIR(11));
			else if (status[i]=='w') wattron(type_space_win,COLOR_PAIR(12));
			else if (status[i]=='u') wattron(type_space_win,COLOR_PAIR(13));
			waddch(type_space_win,(chtype)str[i]);
			if(status[i]=='c')	 wattroff(type_space_win,COLOR_PAIR(11));
			else if (status[i]=='w') wattroff(type_space_win,COLOR_PAIR(12));
			else if (status[i]=='u') wattroff(type_space_win,COLOR_PAIR(13));

			if(getcurx(type_space_win)+1==getmaxx(type_space_win))
				wmove(type_space_win,getcury(type_space_win)+1,1);
			++i;
		}
		if(!(x==-1 || y==-1))
			wmove(type_space_win,y,x);
		free(str);free(status);

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

static void color_fill(){
	struct rgb def_fg,def_bg;
	short fg_num,bg_num;
	pair_content(0, &fg_num, &bg_num);
	color_content(fg_num, &def_fg.r, &def_fg.g, &def_fg.b);
	color_content(bg_num, &def_bg.r, &def_bg.g, &def_bg.b);

	struct rgb* l[][2]={
		{&type_page.color_page.fg	,&def_fg},
		{&type_page.color_page.bg	,&def_bg},

		{&type_page.type_space.color_border.fg	,&type_page.color_page.fg},
		{&type_page.type_space.color_border.bg	,&type_page.color_page.bg},

		{&type_page.challenge_space.color_border.fg	,&type_page.color_page.fg},
		{&type_page.challenge_space.color_border.bg	,&type_page.color_page.bg},

		{&type_page.type_space.color.fg	,&type_page.color_page.fg},
		{&type_page.type_space.color.bg	,&type_page.color_page.bg},

		{&type_page.challenge_space.color.fg	,&type_page.color_page.fg},
		{&type_page.challenge_space.color.bg	,&type_page.color_page.bg},

		{&type_page.color_untyped.fg	,&type_page.type_space.color.fg},
		{&type_page.color_untyped.bg	,&type_page.type_space.color.bg},

		{&type_page.color_correct.fg	,&type_page.type_space.color.fg},
		{&type_page.color_correct.bg	,&type_page.type_space.color.bg},

		{&type_page.color_wrong.fg	,&type_page.type_space.color.fg},
		{&type_page.color_wrong.bg	,&type_page.type_space.color.bg},
	};
	for(long unsigned int i=0;i<sizeof(l)/sizeof(l[0]);++i){
		struct rgb* set=l[i][0];
		struct rgb* def=l[i][1];
		if(set->r==-1) set->r=def->r;
		if(set->g==-1) set->g=def->g;
		if(set->b==-1) set->b=def->b;
	}
}
