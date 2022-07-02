/*
** EPITECH PROJECT, 2022
** dante
** File description:
** tests_increment_case
*/

#include "unit_tests.h"

Test(increment_case, global_test)
{
    char **map = create_map(3, 3);
    valid_dir_t valid_dir;

    map[1][1] = 1;
    map[1][0] = 1;
    map[1][2] = 2;
    valid_dir = get_valid_dir(map, 1, 1, DOWN);
    increment_case(map, 1, 1, valid_dir);

    cr_assert(map[0][0] == 0);
    cr_assert(map[0][1] == 0);
    cr_assert(map[0][2] == 0);
    cr_assert(map[1][0] == 2);
    cr_assert(map[1][1] == 0);
    cr_assert(map[1][2] == 2);
    cr_assert(map[2][0] == 0);
    cr_assert(map[2][1] == 1);
    cr_assert(map[2][2] == 0);
    my_free_word_array(map);
}

Test(increment_case, global_test_2)
{
    char **map = create_map(3, 3);
    valid_dir_t valid_dir;

    map[0][1] = 1;
    map[1][1] = 1;
    map[2][1] = 2;
    valid_dir = get_valid_dir(map, 1, 1, RIGHT);
    increment_case(map, 1, 1, valid_dir);

    cr_assert(map[0][0] == 0);
    cr_assert(map[0][1] == 2);
    cr_assert(map[0][2] == 0);
    cr_assert(map[1][0] == 0);
    cr_assert(map[1][1] == 0);
    cr_assert(map[1][2] == 1);
    cr_assert(map[2][0] == 0);
    cr_assert(map[2][1] == 2);
    cr_assert(map[2][2] == 0);
    my_free_word_array(map);
}
