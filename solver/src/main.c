/*
** EPITECH PROJECT, 2019
** solver
** File description:
** main
*/

#include "my.h"

static char *open_file(char *file)
{
    struct stat openfile;
    int fd = open(file, O_RDONLY);
    size_t size;
    char *buffer;

    if (fd == -1)
        exit(84);
    stat(file, &openfile);
    size = openfile.st_size;
    buffer = malloc(sizeof(char) * (size + 1));
    if (read(fd, buffer, size) == 0)
        exit(84);
    buffer[size] = '\0';
    close(fd);
    return (buffer);
}

static char **malloc_tab(char **tab, solver_t *so)
{
    int i = 0;

    tab = malloc(sizeof(char *) * (so->height + 1));
    for (; i != so->height; i++)
        tab[i] = malloc(sizeof(char) * (so->width + 1));
    if (!tab)
        exit(84);
    return (tab);
}

static char **transform_array(char *str, solver_t *so)
{
    char **tab = NULL;
    int i = 0;
    int j = 0;
    int k = 0;

    so->height = get_nb_lines(str, so);
    so->width = get_nb_cols(str, so);
    tab = malloc_tab(tab, so);
    for (; i != so->height; i++) {
        for (; j < so->width; j++) {
            tab[i][j] = str[k];
            k++;
        }
        tab[i][j] = '\0';
        j = 0;
        k++;
    }
    tab[i] = NULL;
    return (tab);
}

static void test_buffer(char *dest)
{
    int i = 0;

    while (dest[i] != '\0') {
        if (dest[i] != '*' && dest[i] != 'X' && dest[i] != '\n')
            exit(84);
        i++;
    }
    check_buffer(dest, i);
}

int main(int ac, char **av)
{
    char *dest;
    solver_t *so;

    if (ac != 2)
        return (84);
    if (!(so = malloc(sizeof(solver_t))))
        exit(84);
    dest = open_file(av[1]);
    test_buffer(dest);
    so->tab = transform_array(dest, so);
    algorithm_solver(so);
    return (1);
}