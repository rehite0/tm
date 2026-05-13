#pragma once
extern struct GAP_BUFF{
	char* arr;
	char* status; /* u-untyped w-wrong c-correct*/
	int lp;
	int rp;
	int size;
}gap_buff;

struct gb_status{
	char* str;
	char* status;
	int size;
};

extern void gb_init(char* str,int n,int size);
extern void gb_del();
extern void gb_push(char ch);
extern void gb_pop();
extern struct gb_status gb_get_status();
