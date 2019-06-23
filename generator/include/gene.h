/*
** EPITECH PROJECT, 2019
** generator.h
** File description:
** maze
*/

#ifndef GEN_S
#define GEN_S

typedef struct coord_s
{
    char north;
    char west;
    int east;
    int south;
}coord_t;

char **malloc_maze(char **maze, int width, int height);
int generate_imperfect(int width, int height);
int generate_perfect(int width, int height);
char **maze_maker(char **new_maze, int width);
void perfect_maze(char **maze, coord_t *maze_coord);
int check_last(char **maze, int width, int height);
int init_struct(coord_t *maze_coord, int width, int height);
int printation(char **maze);
char changes(char **new_maze, int i, int j);

#endif
