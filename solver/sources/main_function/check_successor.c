/*
** EPITECH PROJECT, 2022
** dante
** File description:
** check_successor
*/

#include "my.h"

int check_lists(const control_list_t *control, const llist_t *child)
{
    llist_t *find_in_list = search_node(control->open_list, child->x,
    child->y);

    if (find_in_list != NULL) {
        if (child->heuristic < find_in_list->heuristic)
            return (1);
        return (-1);
    }
    find_in_list = search_node(control->closed_list, child->x, child->y);
    if (find_in_list != NULL) {
        if (child->heuristic < find_in_list->heuristic)
            return (1);
        return (-1);
    }
    return (1);
}

void change_child_pos(int *x, int *y, const int dir)
{
    if (dir == UP)
        *y -= 1;
    if (dir == RIGHT)
        *x += 1;
    if (dir == DOWN)
        *y += 1;
    if (dir == LEFT)
        *x -= 1;
}

control_list_t *create_successor(control_list_t *control, llist_t *parent,
const int dir, stmap_t maze_info)
{
    int child_x = parent->x;
    int child_y = parent->y;
    int heuristic = 0;
    llist_t *child = NULL;

    change_child_pos(&child_x, &child_y, dir);
    heuristic = calc_heuristic(child_x, child_y, maze_info,
    parent->path_len + 1);
    child = create_node(child_x, child_y, parent->path_len + 1, heuristic);
    if (child == NULL)
        exit(EXIT_ERROR);
    if (check_lists(control, child) < 0) {
        free(child);
        return (control);
    }
    child->parent = parent;
    remove_node(control->open_list, child->x, child->y);
    remove_node(control->closed_list, child->x, child->y);
    control->open_list = pushfront(child, control->open_list);
    return (control);
}

control_list_t *handle_successor(control_list_t *control, llist_t *parent,
stmap_t maze_info)
{
    valid_dir_t dir = solver_get_valid_dir(maze_info, parent);

    if (dir.left == 1)
        control = create_successor(control, parent, LEFT, maze_info);
    if (dir.up == 1)
        control = create_successor(control, parent, UP, maze_info);
    if (dir.right == 1)
        control = create_successor(control, parent, RIGHT, maze_info);
    if (dir.down == 1)
        control = create_successor(control, parent, DOWN, maze_info);
    return (control);
}
