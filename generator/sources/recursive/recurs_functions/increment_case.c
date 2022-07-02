/*
** EPITECH PROJECT, 2022
** dante
** File description:
** increment_case
*/

#include "my.h"

void increment_case(char **map, int x, int y, valid_dir_t valid_dir)
{
    map[y][x] -= 1;
    if (valid_dir.up == 1)
        map[y - 1][x] += 1;
    if (valid_dir.right == 1)
        map[y][x + 1] += 1;
    if (valid_dir.down == 1)
        map[y + 1][x] += 1;
    if (valid_dir.left == 1)
        map[y][x - 1] += 1;
}
