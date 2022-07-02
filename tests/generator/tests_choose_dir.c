/*
** EPITECH PROJECT, 2022
** dante
** File description:
** tests_choose_dir
*/

#include "unit_tests.h"

Test(choose_directions, choose_directions)
{
    valid_dir_t valid_dir1 = {1, 0, 1, 0};
    int available_dir = is_any_directions(valid_dir1);
    int res = choose_directions(valid_dir1, available_dir);
    cr_assert(res == UP || res == DOWN);

    valid_dir_t valid_dir2 = {0, 1, 0, 1};
    available_dir = is_any_directions(valid_dir2);
    res = choose_directions(valid_dir2, available_dir);
    cr_assert(res == RIGHT || res == LEFT);
}
