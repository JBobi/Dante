/*
** EPITECH PROJECT, 2022
** dante
** File description:
** a_star
*/

#include "my.h"

static llist_t *main_loop(const stmap_t maze_info, control_list_t *control)
{
    llist_t *shortest = NULL;

    while (control->open_list != NULL) {
        shortest = get_smallest_heuristic(control->open_list);
        if (shortest->x == maze_info.x - 1 &&
        shortest->y == maze_info.y - 1)
            return (shortest);
        else {
            control->open_list = remove_node(control->open_list,
            shortest->x, shortest->y);
            control->closed_list = pushfront(shortest, control->closed_list);
        }
        control = handle_successor(control, shortest, maze_info);
    }
    return (NULL);
}

static control_list_t *init_start(const stmap_t maze_info,
control_list_t *control)
{
    int start_heuristic = calc_heuristic(0, 0, maze_info, 0);
    llist_t *start_node = create_node(0, 0, 0, start_heuristic);

    control->open_list = pushfront(start_node, control->open_list);
    return (control);
}

int a_star(const stmap_t maze_info)
{
    control_list_t *control = init_control_list();
    llist_t *res = NULL;

    if (control == NULL)
        return (EXIT_ERROR);
    if (maze_info.map[0][0] == 'X' ||
    maze_info.map[maze_info.y - 1][maze_info.x - 1] == 'X') {
        free_control_list(control);
        my_putstr("no solution found", 1);
        return (EXIT_SUCCESS);
    } else
        control = init_start(maze_info, control);
    res = main_loop(maze_info, control);
    if (res == NULL)
        my_putstr("no solution found", 1);
    else
        print_solved_maze(res, maze_info);
    free_control_list(control);
    return (EXIT_SUCCESS);
}
