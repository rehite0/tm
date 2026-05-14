
#pragma once
#define LOG_FILE "./tm.log"
#include <stdio.h>


extern FILE* LOG_F;
[[noreturn]] extern void print_usage();
extern void open_log();
