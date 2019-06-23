/*
** EPITECH PROJECT, 2019
** main dante generator
** File description:
** generator
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include "gene.h"

int check_nbr(char *nbr)
{
    int i = 0;

    while (nbr[i] != '\0')
    {
        if (nbr[i] < '0' || nbr[i] > '9') {
            printf("Wrong argument(s). Numbers needed.\n");
            return (-1);
        }
        i++;
    }
    return (0);
}

int check_arguments(char *nbr_one, char *nbr_two)
{
    if (check_nbr(nbr_one) == -1)
        return (-1);
    if (check_nbr(nbr_two) == -1)
        return (-1);
    if (atoi(nbr_one) == 0 || atoi(nbr_two) == 0)
        return (-1);
    return (0);
}

char **maze_maker(char **new_maze, int width)
{
    int j;

    for (int i = 0; new_maze[i] != NULL; i++) {
        for (j = 0; j < width; j++)
            new_maze[i][j] = changes(new_maze, i, j);
        new_maze[i][j] = '\0';
    }
    return (new_maze);
}

char **malloc_maze(char **maze, int width, int height)
{
    int i = 0;

    maze = malloc(sizeof(char *) * (height + 1));
    for (; i != height; i++)
        maze[i] = malloc(sizeof(char) * (width + 1));
    maze[i] = NULL;
    return (maze);
}

int main(int ac, char **av)
{
    srand(time(NULL));
    if (ac > 4 || ac < 3)
        return (84);
    if (check_arguments(av[1], av[2]) == -1)
        return (84);
    if (ac == 3) {
        generate_imperfect(atoi(av[1]), atoi(av[2]));
        return (0);
    }
    else if (ac == 4 && strcmp(av[3], "perfect") == 0) {
        generate_perfect(atoi(av[1]), atoi(av[2]));
        return (0);
    }
    return (0);
}
