PROG = main

OBJS = main.o
CC = gcc
CPFLAGS = -Wall -Wpointer-arith -O2


main: main.o
	$(CC) $(CPFLAGS) -o main  main.o -lm -L/usr/local/lib/ -lncurses

main.o: main.h main.c
	$(CC) $(CPFLAGS) -c main.c

clean:
	rm -f main.o main