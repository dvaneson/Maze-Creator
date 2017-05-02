/* 
 * Donovan Ellison
 * 4-28-2017
 * maze.h
*/

#include "maze.h"

void (*go[4])(char ***, struct location *, int, int) = {goNorth, goEast, goSouth, goWest};




int carve(char *** maze, struct location * size, int row, int col, int direction)
{
    int randDirection, nextDirection;
    (*maze)[row][col] = '0';   
    randDirection = rand() % 3 + 3;
    nextDirection = rand() % 2 + 1;
    direction = (direction + randDirection) % 4;
    go[direction](maze, size, row, col);

    if(randDirection == 5)
        ++nextDirection;
    direction = (direction + nextDirection) % 4;
    go[direction](maze, size, row, col);

    direction = (2 * nextDirection + randDirection) % 4;
    go[direction](maze, size, row, col);
    return 0;
}



/*If walkable either 1 block or 2 blocks away, don't go*/
/*Or if would run into a wall, don't go*/
void goNorth(char *** maze, struct location * size, int row, int col)
{
    if(col - 1 == 0 || col - 2 == 0 || (*maze)[row - 1][col] == '0' || (*maze)[row - 2][col] == '0')
        return;
    else
        carve(maze, size, --row, col, 0);
}



void goEast(char *** maze, struct location * size, int row, int col)
{
    if(col - 1 == 0 || col - 2 == 0 || (*maze)[row - 1][col] == '0' || (*maze)[row - 2][col] == '0')
        return;
    else
        carve(maze, size, --row, col, 0);
}



void goSouth(char *** maze, struct location * size, int row, int col)
{
    if(col - 1 == 0 || col - 2 == 0 || (*maze)[row - 1][col] == '0' || (*maze)[row - 2][col] == '0')
        return;
    else
        carve(maze, size, --row, col, 0);
}



void goWest(char *** maze, struct location * size, int row, int col)
{
    if(col - 1 == 0 || col - 2 == 0 || (*maze)[row - 1][col] == '0' || (*maze)[row - 2][col] == '0')
        return;
    else
        carve(maze, size, --row, col, 0);
}
