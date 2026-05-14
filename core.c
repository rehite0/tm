#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "./doth/core.h"
#include "./doth/utils.h"

typedef unsigned long int ull;

void gb_init(char* str,int n,int size){
	assert(gap_buff.arr==NULL&&"gap buffer is unintialize or unclear");
	assert(gap_buff.status==NULL&&"gap buffer is unintialize or unclear");
	gap_buff.size=size;
	gap_buff.arr=(char*)malloc((ull)gap_buff.size*sizeof(char));
	gap_buff.status=(char*)malloc((ull)gap_buff.size*sizeof(char));
	assert(gap_buff.arr && gap_buff.status && "malloc failed");
	gap_buff.lp=0;
	gap_buff.rp=gap_buff.size-n;
	for(int i=0;i<gap_buff.size;++i) gap_buff.status[i]='\0';
	for(int i=0;i<n;++i){
		gap_buff.arr[gap_buff.rp+i]=str[i];
		gap_buff.status[gap_buff.rp+i]='u';
	}
}

void gb_del(){
	free(gap_buff.arr);
	free(gap_buff.status);
	gap_buff.arr=0;
	gap_buff.status=0;
	gap_buff.size=0;
	gap_buff.lp=0;
	gap_buff.rp=0;
	// gb_log();
}

void gb_push(char ch){
	if(gap_buff.lp==gap_buff.rp) return;
	gap_buff.arr[gap_buff.lp]=ch;
	gap_buff.status[gap_buff.lp]='w';
	if(gap_buff.arr[gap_buff.lp]==gap_buff.arr[gap_buff.rp]){
		gap_buff.status[gap_buff.rp]='\0';
		++gap_buff.rp;
		gap_buff.status[gap_buff.lp]='c';
	}
	++gap_buff.lp;
	assert(gap_buff.lp>=0);
	assert(gap_buff.rp<=gap_buff.size);
	// gb_log();
}

void gb_pop(){
	if(gap_buff.lp==0) return;
	--gap_buff.lp;
	if(gap_buff.status[gap_buff.lp]=='c'){
		gap_buff.arr[--gap_buff.rp]=gap_buff.arr[gap_buff.lp];
		gap_buff.status[gap_buff.rp]='u';
	}
	gap_buff.status[gap_buff.lp]='\0';
	assert(gap_buff.lp>=0);
	assert(gap_buff.rp<=gap_buff.size);
}

void gb_get_status(char** str,char** status){
	int n=gap_buff.size;
	char* str_=(char*)calloc((ull)n+1,sizeof(char));
	char* status_=(char*)calloc((ull)n+1,sizeof(char));
	assert(str_&&status_&&"malloc failed");

	for(int i=0,j=0;i<n;++i){
		if(gap_buff.status[i]!='\0'){
			str_[j]=gap_buff.arr[i];
			status_[j]=gap_buff.status[i];
			++j;
		}
	}

	*str=str_;
	*status=status_;
	return;
}

void gb_log(){
#ifdef LOG_FILE
	fprintf(LOG_F,
			"size: %d\n"
			"lp: %d ,rp: %d\n",
		gap_buff.size,gap_buff.lp,gap_buff.rp);
	for(int i=0;i<gap_buff.size;++i)
		fprintf(LOG_F,"%c",gap_buff.arr[i]=='\0'?'*':gap_buff.arr[i]);
	fprintf(LOG_F,"\n");
	for(int i=0;i<gap_buff.size;++i)
		fprintf(LOG_F,"%c",gap_buff.status[i]=='\0'?'*':gap_buff.status[i]);
	fprintf(LOG_F,"\n");
	fflush(LOG_F);
#endif
}
