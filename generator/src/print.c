/*
** EPITECH PROJECT, 2019
** dante
** File description:
** print fct
*/

#include <stdio.h>
#include <string.h>
#include "gene.h"

int printation(char **maze)
{
    int i = 0;

    if (maze[1] == NULL) {
        printf("%s", maze[0]);
        return (0);
    }
    for (; maze[i + 1] != NULL; i++)
        printf("%s\n", maze[i]);
    printf("%s", maze[i]);
    return (0);
}