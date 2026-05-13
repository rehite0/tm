#include <assert.h>
#include <stdlib.h>
#include "./doth/core.h"

void gb_init(char* str,int n,int size){
	assert(gap_buff.arr==NULL&&"gap buffer is unintialize or unclear");
	gap_buff.size=size;
	gap_buff.arr=(char*)malloc(gap_buff.size*sizeof(char));
	gap_buff.status=(char*)malloc(gap_buff.size*sizeof(char));
	gap_buff.lp=0;
	gap_buff.rp=gap_buff.size-n;
	for(inti=0;i<gap_buff;++i) gap_buff.status[i]='\0';
	for(int i=0;i<n;++i){
		gap_buff.arr[gap_buff.rp+i]=str[i];
		gap_buff.status[gap_buff.rp+i]='u';
	}
}
void gb_del(){
	free(gap_buff.arr);
	gap_buff.arr=0;
	gap_buff.size=0;
	gap_buff.lp=0;
	gap_buff.rp=0;
}
void gb_push(char ch){
	if(gap_buff.lp==gap_buff.rp) return;
	gap_buff.arr[gap_buff.lp++]=ch;
	if
}
char gb_pop();
struct gb_status gb_get_status();
