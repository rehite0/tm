
#include "./doth/utils.h"
#include <stdio.h>
#include <stdlib.h>

FILE* LOG_F=NULL;

[[noreturn]] void print_usage(){
	printf("incorrect use\n");
	fflush(stdout);
	exit(1);
}
void open_log(){
#ifdef LOG_FILE
	LOG_F=fopen(LOG_FILE,"a");
#endif
}
