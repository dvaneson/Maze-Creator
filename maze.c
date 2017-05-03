/* 
 * Donovan Ellison
 * 4-28-2017
 * maze.h
*/

#include "maze.h"

void (*go[4])(char ***, struct location *, int, int) = {goNorth, goEast, goSouth, goWest};




int carve(char *** maze, struct location * size, int row, int col, int direction)
{
    int randDirection, nextDirection, i;
    (*maze)[row][col] = '0';   
    for(i = 0; i < size->row; ++i)
    {
        printf("%s", (*maze)[i]);
    }
    printf("\n");
    randDirection = rand() % 3 + 3;
    nextDirection = rand() % 2 + 1;
    direction = (direction + randDirection) % 4;
    go[direction](maze, size, row, col);

    if(randDirection == 5)
        ++nextDirection;
    direction = (direction + nextDirection) % 4;
    go[direction](maze, size, row, col);

    direction = (direction + 2 * nextDirection + randDirection) % 4;
    go[direction](maze, size, row, col);
    return 0;
}



void goNorth(char *** maze, struct location * size, int row, int col)
{
    int i, j;
    int move = 1;
    /*If at edge of array*/
    if(row - 1 == 0)
        return;

    /*If it would create a circular path*/
    for(i = 1; i <= 2; ++i)
        for(j = -1; j <= 1; ++j)
            if((*maze)[row - i][col + j] == '0')
                move = 0;

    if(move)
        carve(maze, size, --row, col, 0);
}



void goEast(char *** maze, struct location * size, int row, int col)
{
    int i, j;
    int move = 1;

    if(col + 2 == size->col)
        return;

    /*If it would create a circular path*/
    for(i = 1; i <= 2; ++i)
        for(j = -1; j <= 1; ++j)
            if((*maze)[row + j][col + i] == '0')
                move = 0;

    if(move)
        carve(maze, size, row, ++col, 1);
}



void goSouth(char *** maze, struct location * size, int row, int col)
{
    int i, j;
    int move = 1;

    if(row + 2 == size->row)
        return;

    /*If it would create a circular path*/
    for(i = 1; i <= 2; ++i)
        for(j = -1; j <= 1; ++j)
            if((*maze)[row + i][col + j] == '0')
                move = 0;
    if(move)
        carve(maze, size, ++row, col, 2);
}



void goWest(char *** maze, struct location * size, int row, int col)
{
    int i, j;
    int move = 1;

    if(col - 1 == 0)
        return;

    /*If it would create a circular path*/
    for(i = 1; i <= 2; ++i)
        for(j = -1; j <= 1; ++j)
            if((*maze)[row + j][col - i] == '0')
                move = 0;

    if(move)
        carve(maze, size, row, --col, 3);
}
