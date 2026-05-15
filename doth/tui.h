#pragma once
struct rgb{short r; short g; short b;};
struct C_PAIR{
	struct rgb fg;
	struct rgb bg;
};
struct win{
	int x;
	int y;
	int w;
	int h;
	struct rgb bg;
};
extern struct TYPE_PAGE{
	struct win challenge_space;
	struct win type_space;
	struct C_PAIR color_wrong;
	struct C_PAIR color_correct;
	struct C_PAIR color_untyped;
	// struct C_PAIR color_cursor;
	// unsigned char* cursor_char;
} type_page;
struct result_page{
	int a;
};

extern void tui_main();
