/*
** EPITECH PROJECT, 2022
** dante
** File description:
** get_valid_dir
*/

#include "my.h"

int check_case_up(char **map, int x, int y, int dir)
{
    if (y == 0)
        return (-1);
    if (dir == DOWN)
        return (-2);
    if (map[y - 1][x] == -1 || map[y - 1][x] == 2)
        return (-3);
    return (1);
}

int check_case_right(char **map, int x, int y, int dir)
{
    if (map[y][x + 1] == LINE_END)
        return (-1);
    if (dir == LEFT)
        return (-2);
    if (map[y][x + 1] == -1 || map[y][x + 1] == 2)
        return (-3);
    return (1);
}

int check_case_down(char **map, int x, int y, int dir)
{
    if (map[y + 1] == NULL)
        return (-1);
    if (dir == UP)
        return (-2);
    if (map[y + 1][x] == -1 || map[y + 1][x] == 2)
        return (-3);
    return (1);
}

int check_case_left(char **map, int x, int y, int dir)
{
    if (x == 0)
        return (-1);
    if (dir == RIGHT)
        return (-2);
    if (map[y][x - 1] == -1 || map[y][x - 1] == 2)
        return (-3);
    return (1);
}

valid_dir_t get_valid_dir(char **map, int x, int y, int dir)
{
    valid_dir_t valid_dir;

    valid_dir.up = check_case_up(map, x, y, dir);
    valid_dir.right = check_case_right(map, x, y, dir);
    valid_dir.down = check_case_down(map, x, y, dir);
    valid_dir.left = check_case_left(map, x, y, dir);
    return (valid_dir);
}
