/*
** EPITECH PROJECT, 2022
** dante
** File description:
** create_stmap
*/

#include "my.h"

static int get_maze_height(char *const *maze)
{
    int res = 0;

    while (maze[res])
        res += 1;
    return (res);
}

stmap_t solver_get_stmap(char **maze)
{
    stmap_t map;

    map.map = maze;
    map.x = my_strlen(maze[0]);
    map.y = get_maze_height(maze);
    return (map);
}
