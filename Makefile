palette.o: palette.c palette.h
	gcc -c palette.c -o palette.o

main.o: main.c
	gcc -c main.c -o main.o

format.o: format.c
	gcc -c format.c -o format.o

all: palette.o main.o format.o
	gcc main.o palette.o format.o -lm -o paletter
