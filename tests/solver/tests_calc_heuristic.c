/*
** EPITECH PROJECT, 2022
** dante
** File description:
** tests_calc_heuristic
*/

#include "unit_tests.h"

Test(get_absolute_value, abs)
{
    int neg = -42;
    cr_assert(get_absolute_value(neg) == 42);

    int pos = 42;
    cr_assert(get_absolute_value(pos) == 42);
}

Test(calc_heuristic, heuristic)
{
    stmap_t maze = {NULL, 3, 3};

    int heuristic_far = calc_heuristic(0, 1, maze, 1);
    int heuristic_close = calc_heuristic(1, 1, maze, 2);

    cr_assert(heuristic_close < heuristic_far);
}
