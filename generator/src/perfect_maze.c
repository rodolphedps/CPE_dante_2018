/*
** EPITECH PROJECT, 2019
** Dante
** File description:
** perfect_maze
*/

#include <stdlib.h>
#include "gene.h"

int cond_coord_north(char **maze, coord_t *maze_coord, int i, int j)
{
    if (i - 1 >= 0)
        if (maze[i - 1][j] == 'X')
            maze_coord->north = 'X';
    if (j - 1 >= 0) {
        if (maze[i][j - 1] == 'X')
            maze_coord->west = 'X';
    }
    if (i - 1 >= 0) {
        if (maze_coord->north == 'X' && maze_coord->west == '*')
            maze[i - 1][j] = '*';
    }
    return (0);
}

int cond_coord_i(char **maze, coord_t *maze_coord, int i, int j)
{
    if (i == 0)
        maze[i][j] = '*';
    cond_coord_north(maze, maze_coord, i, j);
    if (j - 1 >= 0)
        if (maze_coord->north == '*' && maze_coord->west == 'X')
            maze[i][j - 1] = '*';
    return (0);
}

int random_moove(char **maze, coord_t *maze_coord, int i, int j)
{
    int random;

    if (maze_coord->north != 'X' || maze_coord->west != 'X')
        return (0);
    random = rand() % 2;
    if (j - 1 >= 0 && random == 0)
        maze[i][j - 1] = '*';
    else if (i - 1 >= 0 && random == 1)
        maze[i - 1][j] = '*';
    return (0);
}

void perfect_maze(char **maze, coord_t *maze_coord)
{
    int i = 0;
    int j;

    while (i < maze_coord->south) {
        j = 0;
        maze_coord->west = '*';
        maze_coord->north = '*';
        while (j < maze_coord->east) {
            cond_coord_i(maze, maze_coord, i, j);
            random_moove(maze, maze_coord, i, j);
            j += 2;
        }
        i += 2;
    }
}

int generate_perfect(int width, int height)
{
    coord_t *maze_coord = malloc(sizeof(coord_t));
    char **maze = NULL;

    init_struct(maze_coord, width, height);
    if (width < 1 || height < 1)
        exit(84);
    maze = malloc_maze(maze, width, height);
    maze = maze_maker(maze, width);
    perfect_maze(maze, maze_coord);
    check_last(maze, width, height);
    printation(maze);
    return (0);
}