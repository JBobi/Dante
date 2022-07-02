/*
** EPITECH PROJECT, 2022
** dante
** File description:
** tests_create_stmap
*/

#include "unit_tests.h"

Test(create_stmap, create_structure)
{
    char **map = create_map(3, 5);

    for (int y = 0; map[y] != NULL; y++) {
        for (int x = 0; x < 3; x++)
            cr_assert(map[y][x] == 0);
        cr_assert(map[y][3] == LINE_END);
    }
    cr_assert(map[5] == NULL);
    my_free_word_array(map);
}
