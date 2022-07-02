/*
** EPITECH PROJECT, 2022
** dante
** File description:
** check_case
*/

#include "my.h"

static int check_up(const stmap_t maze_info, const llist_t *parent)
{
    if (parent->y == 0)
        return (-1);
    if (maze_info.map[parent->y - 1][parent->x] == 'X')
        return (-2);
    if (parent->parent && parent->parent->y == parent->y - 1)
        return (-3);
    return (1);
}

static int check_right(const stmap_t maze_info, const llist_t *parent)
{
    if (parent->x == maze_info.x - 1)
        return (-1);
    if (maze_info.map[parent->y][parent->x + 1] == 'X')
        return (-2);
    if (parent->parent && parent->parent->x == parent->x + 1)
        return (-3);
    return (1);
}

static int check_down(const stmap_t maze_info, const llist_t *parent)
{
    if (parent->y == maze_info.y - 1)
        return (-1);
    if (maze_info.map[parent->y + 1][parent->x] == 'X')
        return (-2);
    if (parent->parent && parent->parent->y == parent->y + 1)
        return (-3);
    return (1);
}

static int check_left(const stmap_t maze_info, const llist_t *parent)
{
    if (parent->x == 0)
        return (-1);
    if (maze_info.map[parent->y][parent->x - 1] == 'X')
        return (-2);
    if (parent->parent && parent->parent->x == parent->x - 1)
        return (-3);
    return (1);
}

valid_dir_t solver_get_valid_dir(const stmap_t maze_info,
const llist_t *parent)
{
    valid_dir_t valid_dir;

    valid_dir.up = check_up(maze_info, parent);
    valid_dir.right = check_right(maze_info, parent);
    valid_dir.down = check_down(maze_info, parent);
    valid_dir.left = check_left(maze_info, parent);
    return (valid_dir);
}
