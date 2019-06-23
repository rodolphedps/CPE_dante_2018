/*
** EPITECH PROJECT, 2019
** CPE_dante_2018
** File description:
** test_gene
*/

#include "gene.h"
#include <criterion/criterion.h>

/*Test(bad_nb_args, too_much_args)
{
    char **av = malloc(sizeof(char *) * 2);
    int ac = 2;

    av[0] = "./generator";
    av[1] = "10";
    cr_assert(check_arguments(ac, av) == 84);
}*/

Test(generate_imperfect, is_ok)
{
    char **av = malloc(sizeof(char *) * 3);

    av[0] = "./generator";
    av[1] = "10";
    av[2] = "10";
    cr_assert(generate_imperfect(atoi(av[1]), atoi(av[2])) == 0);
}