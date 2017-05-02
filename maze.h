/*
 * Donovan Ellison
 * 4-28-2017
 * maze.h
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

struct location
{
	int col;
	int row;
};

int carve(char ***, struct location *, int, int, int);
void goNorth(char ***, struct location *, int, int);
void goEast(char ***, struct location *, int, int);
void goSouth(char ***, struct location *, int, int);
void goWest(char ***, struct location *, int, int);
