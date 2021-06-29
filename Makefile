SRC_FILES = main.c
CC = gcc
CFLAGS = -I.

all:
	${CC} ${SRC_FILES} ${CFLAGS} -o tvm
