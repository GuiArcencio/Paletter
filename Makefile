palette.o: palette.c palette.h
	gcc -c palette.c -o palette.o

main.o: main.c
	gcc -c main.c  -o main.o

all: palette.o main.o
	gcc main.o palette.o -lm -o paletter
