CFLAGS = -g -Wall -ansi -pedantic -O0

recBack: main.c maze.c maze.h
	gcc $(CFLAGS) -o recBack main.c maze.c

clean:
	rm -f *.o recBack rand.txt
