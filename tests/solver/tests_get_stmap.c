/*
** EPITECH PROJECT, 2022
** dante
** File description:
** tests_get_stmap
*/

#include "unit_tests.h"

Test(solver_get_stmap, valid_case)
{
    char **maze = get_maze(VALID_MAZE);
    stmap_t map = solver_get_stmap(maze);

    cr_assert(word_array_comp(map.map, maze) == 0);
    cr_assert(map.x == 5);
    cr_assert(map.y == 5);
    my_free_word_array(maze);
}
