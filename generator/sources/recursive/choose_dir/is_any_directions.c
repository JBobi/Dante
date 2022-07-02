/*
** EPITECH PROJECT, 2022
** dante
** File description:
** is_any_directions
*/

#include "my.h"

int is_any_directions(valid_dir_t valid)
{
    int count = 0;

    if (valid.up == 1)
        count += 1;
    if (valid.right == 1)
        count += 1;
    if (valid.down == 1)
        count += 1;
    if (valid.left == 1)
        count += 1;
    return (count);
}
