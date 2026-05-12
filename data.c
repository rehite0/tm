#include "./doth/arg.h"
#include "./doth/tui.h"

struct ARG_DS arg_ds={
	.mode=2
};

struct TYPE_PAGE type_page={
	.challenge_space={
		.x=10, .y=4, .h=5, .w=65
	},
	.type_space={
		.x=10, .y=12, .h=5, .w=65
	},
	.cursor_char=u8"|"
};
