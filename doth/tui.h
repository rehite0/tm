
struct rgb{char r; char g; char b;};
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
	struct rgb color_wrong;
	struct rgb color_correct;
	struct rgb color_untyped;
	struct rgb color_cursor;
	unsigned char* cursor_char;
} type_page;
struct result_page{
	int a;
};

extern void tui_main();
