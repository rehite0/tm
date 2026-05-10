
struct rgb{char r; char g; char b;};
struct pos{int x; int y;};
struct panel{
	struct pos ancore;
	int w;
	int h;
	struct rgb bg;
};
extern struct TYPE_PAGE{
	struct panel target_text;
	struct panel test_text;
	struct rgb color_wrong;
	struct rgb color_correct;
	struct rgb color_untyped;
	struct rgb color_cursor;
	char* cursor_char;
} type_page;
struct result_page{};

extern void tui_main();

