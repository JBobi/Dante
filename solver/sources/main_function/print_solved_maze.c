/*
** EPITECH PROJECT, 2022
** dante
** File description:
** print_solved_maze
*/

#include "my.h"

void print_solved_maze(llist_t *end, stmap_t maze_info)
{
    llist_t *temp = end;

    while (temp) {
        maze_info.map[temp->y][temp->x] = 'o';
        temp = temp->parent;
    }
    for (int i = 0; maze_info.map[i + 1]; i++) {
        my_putstr(maze_info.map[i], 1);
        my_putchar('\n');
    }
    my_putstr(maze_info.map[maze_info.y - 1], 1);
}
