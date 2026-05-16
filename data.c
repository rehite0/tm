#include "./doth/arg.h"
#include "./doth/tui.h"
#include "./doth/core.h"

struct ARG_DS arg_ds={
	.mode=2
};

struct TYPE_PAGE type_page={
	.challenge_space={
		.x=10, .y=4, .h=5, .w=65,
		.color_border	={ .fg={   -1,  -1,  -1 } , .bg={ -1,-1,-1 } },
		.color		={ .fg={   -1,  -1,  -1 } , .bg={ -1,-1,-1 } }

	},
	.type_space={
		.x=10, .y=12, .h=5, .w=65,
		.color_border	={ .fg={   -1,  -1,  -1 } , .bg={ -1,-1,-1 } },
		.color		={ .fg={   -1,  -1,  -1 } , .bg={ -1,-1,-1 } }
	},
	.color_correct	={ .fg={    0,1000,   0 } , .bg={ -1,-1,-1 } },
	.color_wrong	={ .fg={  1000,  0,   0 } , .bg={ -1,-1,-1 } },
	.color_untyped	={ .fg={  550, 550, 550 } , .bg={ -1,-1,-1 } },
	.color_page	={ .fg={   -1,  -1,  -1 } , .bg={ -1,-1,-1 } },
	// .cursor_char=u8"|"
};
struct GAP_BUFF gap_buff={
	.arr=0, .status=0, .lp=0 ,.rp=0,.size=0
};
