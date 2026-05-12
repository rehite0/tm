#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <getopt.h>
#include "./doth/arg.h"
#include "./doth/tui.h"

void print_usage();

int main(int argc,char* argv[] ){
	setlocale(LC_ALL, "");
	int c;
	// int digit_optind = 0;


	for (;;) {
		// int this_option_optind = optind ? optind : 1;
		int option_index = 0;
		static struct option long_options[] = {
			{"cli",  no_argument,&arg_ds.mode,  1 },
			{"tui",  no_argument,&arg_ds.mode,  2 },
			{"gui",  no_argument,&arg_ds.mode,  3 },
			// {"add",     required_argument, 0,  1 },
			// {"delete",  required_argument, 0,  1 },
			// {"verbose", no_argument,       0,  1 },
			// {"create",  required_argument, 0, 'c'},
			// {"file",    required_argument, 0,  1 },
			{0,         0,                 0,  0 }
		};

		c = getopt_long(argc, argv, "abc:d:012",
				long_options, &option_index);
		if (c == -1)
			break;

		switch (c) {

			default:
				print_usage();
			// case 0:
			// 	printf("option %s", long_options[option_index].name);
			// 	if (optarg)
			// 		printf(" with arg %s", optarg);
			// 	printf("\n");
			// 	break;

			// case '2':
			// 	if (digit_optind != 0 && digit_optind != this_option_optind)
			// 		printf("digits occur in two different argv-elements.\n");
			// 	digit_optind = this_option_optind;
			// 	printf("option %c\n", c);
			// 	break;

			// case 'a':
			// 	printf("option a\n");
			// 	break;
			// case 'b':
			// 	printf("option b\n");
			// 	break;

			// case 'c':
			// 	printf("option c with value '%s'\n", optarg);
			// 	break;

			// case 'd':
			// 	printf("option d with value '%s'\n", optarg);
			// 	break;

			// case '?':
			// 	break;

		}
	}

	// if (optind < argc) {
	// 	printf("non-option ARGV-elements: ");
	// 	while (optind < argc)
	// 		printf("%s ", argv[optind++]);
	// 	printf("\n");
	// }
	// 			fprintf(stderr, "Usage: %s [-t nsecs] [-n] name\n",
	// 					argv[0]);
	switch(arg_ds.mode){
		case 1:
			printf("not suported");
			break;
		case 2:
			tui_main();
			break;
		case 3:
			printf("not suported\n");
			break;
		default:
			print_usage();
	}
	printf("exited\n");
	fflush(stdout);
	return 0;
}

[[noreturn]] void print_usage(){
	printf("incorrect use\n");
	fflush(stdout);
	exit(1);
}
