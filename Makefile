CFLAGS = -g -Wall -ansi -pedantic -O0

randMaze: main.c maze.c maze.h
	gcc $(CFLAGS) -o recBackmain.c maze.c

clean:
	rm -f *.o recBack
