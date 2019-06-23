/*
** EPITECH PROJECT, 2019
** solver .h
** File description:
** solver.h
*/

#ifndef SOLVER_S
#define SOLVER_S

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>

typedef struct solver_s {
    char **tab;
    int x;
    int y;
    int width;
    int height;
    int move;
    int count;
    int next;
    int dx;
    int dy;
}              solver_t;

//check if buffer is ok -- is he only composed of '*' && 'X' or not
void check_buffer(char *dest, int i);
void no_solution(void);
void good_end(solver_t *so);

//get the nb of lines of a buffer -- get the nb of columns of a buffer
int get_nb_lines(char *str, solver_t *so);
int get_nb_cols(char *str, solver_t *so);
char **switch_back_n(char **tab, solver_t *so);

//resolve a given maze -- print an array (char **) -- initialise datas for maze
int algorithm_solver(solver_t *so);
void print_array(char **array);
char **end_of_tab(char **tab, solver_t *so);
void init_data(solver_t *so);

#endif /* !SOLVER_S */
