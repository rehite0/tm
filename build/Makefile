CC=gcc
CFLAGS= -Ofast -march='native'
CFLAGS+= -ggdb -Werror -Wall -Wextra -Wpedantic -Wconversion -Winline -Wshadow
CFLAGS+= -Wfloat-equal -Wunreachable-code -Winit-self -Wuninitialized -Wvla
CFLAGS+= -Wvector-operation-performance -Wdisabled-optimization -fanalyzer 
#CPPFLAGS=
#LDFLAGS=
LDLIBS= `pkg-config --libs --cflags ncurses`
OBJ= main.o tui.o data.o core.o utils.o

all: tm.out
	@echo 'compilation finished'
tm.out:${OBJ}
	${CC} ${CFLAGS} ${LDLIBS} ${OBJ} -o tm.out
main.o:../main.c ../doth/arg.h ../doth/tui.h ../doth/utils.h
	${CC} ${CFLAGS} -c ../main.c -o main.o
data.o:../data.c ../doth/arg.h ../doth/tui.h ../doth/core.h ../doth/utils.h
	${CC} ${CFLAGS} -c ../data.c -o data.o
tui.o:../tui.c ../doth/tui.h ../doth/core.h ../doth/utils.h
	${CC} ${CFLAGS} -c ../tui.c -o tui.o
core.o:../core.c ../doth/core.h ../doth/utils.h
	${CC} ${CFLAGS} -c ../core.c -o core.o
utils.o:../utils.c ../doth/utils.h
	${CC} ${CFLAGS} -c ../utils.c -o utils.o
clean:
	rm -f *.out *.o
.PHONY: all clean
