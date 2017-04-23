/* Donovan Ellison
 * 4-22-2017
 * main.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct location
{
    int col;
    int row;
};



int main(int argc, char * argv[])
{
    struct location size, start, exit;   
    if(argc < 3)
    {
        size.col = rand()%90 + 10;
        size.row = rand()%90 + 10;
    }
    else
    {
        size.col = strtol(argv[1], &argv[1], 10);
        size.row = strtol(argv[2], &argv[2], 10);
    }
    return 0;
}
