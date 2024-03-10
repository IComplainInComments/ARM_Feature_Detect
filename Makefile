CC=gcc
LD=ld
OPTS=
SRC=ARM_CPU.c

all:
	${CC} ${OPTS} ${SRC} -o bin/ARM_Feature_Detect

debug: 
	${CC} -g ${SRC} -o bin/ARM_Feature_Detect

clean:
	@rm bin/*