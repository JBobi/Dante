/*
** EPITECH PROJECT, 2022
** dante
** File description:
** solver
*/

#include "my.h"

int dante_solver(int ac, char **av)
{
    char **maze = NULL;
    stmap_t maze_info;

    if (ac != 2)
        return (EXIT_ERROR);
    maze = get_maze(av[1]);
    if (maze == NULL)
        return (EXIT_ERROR);
    if (solver_error_handling(maze) < 0) {
        my_free_word_array(maze);
        return (EXIT_ERROR);
    }
    maze_info = solver_get_stmap(maze);
    if (a_star(maze_info) == EXIT_ERROR) {
        my_free_word_array(maze);
        return (EXIT_ERROR);
    }
    my_free_word_array(maze);
    return (EXIT_SUCCESS);
}
