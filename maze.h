/* Donovan Ellison
 * 4-28-2017
 * maze.h
*/

#include <stdio.h>

struct location
{
	int col;
	int row;
};

int create(char ***, int, struct location *);
