/*
** EPITECH PROJECT, 2019
** Dante
** File description:
** Imperfect maze
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "gene.h"

int init_struct(coord_t *maze_coord, int width, int height)
{
    maze_coord->north = '*';
    maze_coord->west = '*';
    maze_coord->east = width;
    maze_coord->south = height;
    return (0);
}

int check_last(char **maze, int width, int height)
{
    int i = width - 1;
    int j = height - 1;

    if (maze[i][j] == 'X') {
        maze[i][j] = '*';
        if (maze[i - 1][j] == 'X' && maze[i][j - 1] == 'X')
            maze[i - 1][j] = '*';
    }
    return (0);
}

int change_wall(char **maze, int i, int j)
{
    if (maze[i][j] == '*')
        return (0);
    if (maze[i - 1][j] == '*' && maze[i + 1][j] == '*')
        if (maze[i][j - 1] == 'X' && maze[i][j + 1] == 'X')
            maze[i][j] = '*';
    return (0);
}

int imperfect_maker(char **maze, int width, int height)
{
    int i = 1;
    int j;

    while (i < width - 1) {
        j = 1;
        while (j < height - 1) {
            change_wall(maze, i, j);
            j++;
        }
        i++;
    }
    return (0);
}

int generate_imperfect(int width, int height)
{
    coord_t *maze_coord = malloc(sizeof(coord_t));
    char **maze = NULL;

    init_struct(maze_coord, width, height);
    if (width < 1 || height < 1)
        exit(84);
    maze = malloc_maze(maze, width, height);
    maze = maze_maker(maze, width);
    perfect_maze(maze, maze_coord);
    imperfect_maker(maze, width, height);
    check_last(maze, width, height);
    printation(maze);
    return (0);
}
