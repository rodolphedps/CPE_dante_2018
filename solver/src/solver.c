/*
** EPITECH PROJECT, 2019
** CPE_dante_2018
** File description:
** algo
*/

#include "my.h"

/*void init_data(solver_t *so)
{
    so->next = 1;
    so->move = 0;
    so->count = 0;
}

static void switch_directions(int *d_x, int *d_y, int move)
{
    d_x[0] = 0;
    d_y[0] = 0;

    switch (move) {
        case 0:
            d_x[0] = 1;
            break;
        case 1:
            d_y[0] = 1;
            break;
        case 2:
            d_x[0] = -1;
            break;
        default:
            d_y[0] = -1;
            break;
    }
}

static void value_cond(solver_t *so)
{
    so->next = 0;
    so->count = 0;
}

char **end_of_tab(char **tab, solver_t *so)
{
    tab[0][0] = 'o';
    tab[(so->height - 1)][(so->width - 1)] = 'o';
    tab[(so->height - 1)][so->width] = '\0';
    return (tab);
}*/

/*int algorithm_solver(char **tab, solver_t *so)
{
    int y = 0;
    int x = 0;
    int d_x = 0;
    int d_y = 0;

    for (; (x < so->width - 1) || (y < so->height - 1); d_x = 0, d_y = 0) {
        switch_directions(&d_x, &d_y, so->move);
        if ((so->next == 1 && tab[(y + d_y)][(x + d_x)] == '*')
        || (so->next == 0 && tab[(y + d_y)][(x + d_x)] == 'o')) {
            tab[y][x] = so->next ? 'o' : '#';
            init_data(so);
            x += d_x;
            y += d_y;
        } else {
            so->move = (so->move + 1) % 4;
            so->count += 1;
            if (so->count > 3)
                value_cond(so);
        }
    }
    return (0);
}*/

int check_poss(solver_t *so, bool move)
{
    int dx = so->dx;
    int dy = so->dy;

    if ((move && so->tab[so->y + dy][so->x + dx] == '*') ||
        (!move && so->tab[so->y + dy][so->x + dx] == 'o')) {
            so->tab[so->y][so->x] = (move) ? 'o' : '#';
            so->y += dy;
            so->x += dx;
            return (1);
    } else
        return (0);
}

void check_end(int *checks, int *move)
{
    if (move[0] == true && checks[0] > 3) {
        move[0] = false;
        checks[0] = 0;
    }
    if (move[0] == false && checks[0] > 4) {
        move[0] = false;
        checks[0] = 0;
    }
}

void start_loop(solver_t *so, int dir)
{
    so->dx = 0;
    so->dy = 0;

    if (dir == 0 && so->x + 1 < so->width) {
        so->dx = 1;
    }
    if (dir == 1 && so->y + 1 < so->height) {
        so->dy = 1;
    }
    if (dir == 2 && so->x != 0) {
        so->dx = -1;
    }
    if (dir == 3 && so->y != 0) {
        so->dy = -1;
    }
}

void is_over(solver_t *so)
{
    static int a = 0;

    if (so->x == so->width - 1 && so->y == so->height - 1)
        good_end(so);
    if (so->x == 0 && so->y == 0 && a > 2) {
        printf("no solution found");
        exit(0);
    }
    a++;
}

int algorithm_solver(solver_t *so)
{
    int dir = 0;
    int checks = 0;
    int move = true;

    so->x = 0;
    so->y = 0;
    while (1) {
        start_loop(so, dir);
        if (check_poss(so, move) == 1) {
            move = true;
            checks = 0;
            dir = 0;
        } else {
            dir = (dir + 1) % 4;
            checks++;
            check_end(&checks, &move);
        }
        is_over(so);
    }
}