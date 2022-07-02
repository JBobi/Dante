/*
** EPITECH PROJECT, 2022
** dante
** File description:
** calc_heuristic
*/

#include "my.h"

int calc_heuristic(int x, int y, stmap_t maze, int path_len)
{
    int heuristic = 0;
    int x_line = get_absolute_value(maze.x - 1 - x);
    int y_line = get_absolute_value(maze.y - 1 - y);

    if (x_line > y_line)
        heuristic = 14 * y_line + 10 * (x_line - y_line);
    else
        heuristic = 14 * x_line + 10 * (y_line - x_line);
    return (path_len + heuristic);
}
