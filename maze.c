/* Donovan Ellison
 * 4-28-2017
 * maze.h
*/

#include "maze.h"


int create(char *** maze, struct location * size, int col, int row)
{
    /*Ranomzie array of pointers to seperate functions, moving different directions*/
    /*i.e. goRight, goUp, etc.*/
    /*If walkable either 1 block or 2 blocks away, don't go*/
    /*Or if would run into a wall, don't go*/
    (*maze)[col][row] = '0';   
    return 0;
}



int goRight(char *** maze, struct location * size, int col, int row)
{
    if(col - 1 == 0 || col + 1 == size.col || row - 1 == 0 || row + 1 == size.row)
        return 0
    else if((*maze)[col][row + 1] == '0' || (*maze)[col][row + 2] == '0')
        return 0;
    else
        return 1; /*Can go here*/
}
