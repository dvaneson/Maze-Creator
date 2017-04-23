CFLAGS = -g -Wall -ansi -pedantic -O0

randMaze: main.c
	gcc $(CFLAGS) -o randMaze main.c # maze.h maze.c

clean:
	rm -f *.o rhr
