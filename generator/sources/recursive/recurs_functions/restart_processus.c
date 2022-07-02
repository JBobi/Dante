/*
** EPITECH PROJECT, 2022
** dante
** File description:
** restart_processus
*/

#include "my.h"

void restart_processus(char **map, int x, int y, int next_dir)
{
    if (next_dir == UP)
        generate_maze(map, x, y - 1, next_dir);
    if (next_dir == RIGHT)
        generate_maze(map, x + 1, y, next_dir);
    if (next_dir == DOWN)
        generate_maze(map, x, y + 1, next_dir);
    if (next_dir == LEFT)
        generate_maze(map, x - 1, y, next_dir);
}
