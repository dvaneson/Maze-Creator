/*
 * Donovan Ellison
 * 4-22-2017
 * main.c
*/

#include <stdio.h>
#include "maze.h"



int main(int argc, char * argv[])
{
    struct location size, start, exit;   
    char ** maze;
    int i, j;
    FILE * filePtr;

    srand(time(NULL));
    /*If executable doesn't come with parameters, do random size*/
    if(argc < 3)
    {
        size.col = rand()%40 + 20;
        size.row = rand()%40 + 20;
    }
    else
    {
        size.col = strtol(argv[1], &argv[1], 10);
        size.row = strtol(argv[2], &argv[2], 10);
    }

    /*Allocating the maze based on size*/
    maze = (char **) malloc(sizeof(char *) * size.row);
    for(i = 0; i < size.row; ++i)
        maze[i] = (char *) malloc(sizeof(char) * (size.col + 1));

    /*Setting everything in the maze to 'X'*/
    for(i = 0; i < size.row; ++i)
    {
        for(j = 0; j < size.col; ++j)
            maze[i][j] = 'X';
        maze[i][j] = '\n';
    }

    start.row = 0;
    start. col = 1;
    exit.row = size.row;
    exit.col = size.col - 1;

    carve(&maze, &size, start.row + 1, start.col, 2);
        

    filePtr = fopen("rand.txt", "w");
    
    /*Printing everything to text file rand.txt*/
    fprintf(filePtr, "%i, %i\n%i, %i\n%i, %i\n", size.col, size.row, start.col, start.row, exit.col, exit.row);
    for(i = 0; i < size.row; ++i)
        fputs(maze[i], filePtr);

    fclose(filePtr);

    /*Deallocating the maze*/
    for(i = 0; i < size.row; ++i)
        free(maze[i]);
    free(maze);

    return 0;
}
