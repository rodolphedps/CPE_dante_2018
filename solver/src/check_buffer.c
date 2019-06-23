/*
** EPITECH PROJECT, 2019
** CPE_dante_2018
** File description:
** check_buffer
*/

#include "my.h"

void no_solution(void)
{
    printf("no solution found");
    exit(0);
}

void check_buffer(char *dest, int i)
{
    int j = 0;

    i = 0;
    if (dest[i] == 'X')
        no_solution();
    for (; dest[j] != '\0'; j++);
    if (dest[j] == 'X')
        no_solution();
}