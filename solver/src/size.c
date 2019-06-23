/*
** EPITECH PROJECT, 2019
** solver
** File description:
** size
*/

#include "my.h"

void good_end(solver_t *so)
{
    char car;

    for (int y = 0; so->tab[y]; y++) {
        for (int x = 0; so->tab[y][x] != '\0'; x++) {
            car = so->tab[y][x];
            so->tab[y][x] = (car == '#') ? '*' : car;
        }
    }
    so->tab[0][0] = 'o';
    so->tab[so->height - 1][so->width - 1] = 'o';
    for (int a = 0; a < so->height; a++) {
        write(1, so->tab[a], strlen(so->tab[a]));
        if (a < so->height - 1)
            write(1, &"\n", 1);
    }
    exit(1);
}

void removing_old(char **array, size_t i, size_t j)
{
    if (array[i][j] == '#')
        array[i][j] = '*';
}

void print_array(char **array)
{
    for (size_t i = 0; array[i] != NULL; i++)
        for (size_t j = 0; array[i][j] != '\0'; j++)
            removing_old(array, i, j);
    for (int i = 0; array[i] != NULL; i++) {
        printf("%s", array[i]);
        if (array[i + 1] != NULL)
            putchar('\n');
    }
}

int get_nb_lines(char *str, solver_t *so)
{
    int i = 1;

    so->height = 0;
    while (str[i] != '\0') {
        if (str[i] == '\n')
            so->height++;
        i++;
    }
    return (so->height);
}

int get_nb_cols(char *str, solver_t *so)
{
    so->width = 0;
    while (str[so->width] != '\n')
        so->width++;
    return (so->width);
}