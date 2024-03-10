CC=gcc
LD=ld
OPTS=
SRC=ARM_CPU.c

all:
	${CC} ${OPTS} ${SRC} -o bin/ARM_CPU

debug: 
	${CC} -g ${SRC} -o bin/ARM_CPU

clean:
	@rm bin/*