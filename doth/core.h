#pragma once
extern struct GAP_BUFF{
	char* arr;
	char* status; /* u-untyped w-wrong c-correct*/
	int lp;
	int rp;
	int size;
}gap_buff;

extern void gb_init(char* str,int n,int size);
extern void gb_del();
extern void gb_push(char ch);
extern void gb_pop();
extern void gb_get_status(char** str,char** status);
extern void gb_log();
