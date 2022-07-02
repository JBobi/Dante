/*
** EPITECH PROJECT, 2022
** dante
** File description:
** error_handling
*/

#include "unit_tests.h"

Test(generator_error_handling, nbr_args)
{
    char *not_enough[] = {"./generator", NULL};
    int res = generator_error_handling(1, not_enough);

    cr_assert(res == -1);
}

Test(generator_error_handling, numbers)
{
    char *first_arg_wrong[] = {"./generator", "0", "56", NULL};
    int first_res = generator_error_handling(3, first_arg_wrong);

    cr_assert(first_res == -2);

    char *second_arg_wrong[] = {"./generator", "71", "-4", NULL};
    int second_res = generator_error_handling(3, second_arg_wrong);

    cr_assert(second_res == -2);
}

Test(generator_error_handling, valid)
{
    char *valid[] = {"./generator", "53", "60", NULL};
    int res = generator_error_handling(3, valid);

    cr_assert(res == 0);
}
