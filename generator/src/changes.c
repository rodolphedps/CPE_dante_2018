/*
** EPITECH PROJECT, 2019
** generator
** File description:
** changes
*/

#include "gene.h"

char changes(char **new_maze, int i, int j)
{
    if (j % 2 == 0 && i % 2 == 0)
        new_maze[i][j] = '*';
    else if (j % 2 == 1 && i % 2 == 0)
        new_maze[i][j] = 'X';
    else if (i % 2 == 1)
        new_maze[i][j] = 'X';
    return (new_maze[i][j]);
}