/*
** EPITECH PROJECT, 2022
** dante
** File description:
** tests_is_any_directions
*/

#include "unit_tests.h"

Test(is_any_directions, no_directions)
{
    valid_dir_t valid_dir = {0, 0, 0, 0};

    cr_assert(!is_any_directions(valid_dir));
}

Test(is_any_directions, up)
{
    valid_dir_t valid = {1, 0, 0, 0};

    cr_assert(is_any_directions(valid) == 1);
}

Test(is_any_directions, right)
{
    valid_dir_t valid = {0, 1, 0, 0};

    cr_assert(is_any_directions(valid) == 1);
}

Test(is_any_directions, down)
{
    valid_dir_t valid = {0, 0, 1, 0};

    cr_assert(is_any_directions(valid) == 1);
}

Test(is_any_directions, left)
{
    valid_dir_t valid = {0, 0, 0, 1};

    cr_assert(is_any_directions(valid) == 1);
}
