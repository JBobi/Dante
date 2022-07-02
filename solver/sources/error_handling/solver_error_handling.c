/*
** EPITECH PROJECT, 2022
** dante
** File description:
** solver_error_handling
*/

#include "my.h"

static int check_line_char(char const *line)
{
    for (int i = 0; line[i]; i++)
        if (line[i] != 'X' && line[i] != '*')
            return (-1);
    return (0);
}

static int check_maze_char(char *const *maze)
{
    for (int i = 0; maze[i]; i++) {
        if (check_line_char(maze[i]) < 0) {
            my_putstr(WRONG_CHAR, 2);
            return (-1);
        }
    }
    return (0);
}

static int check_maze_line_size(char *const *maze)
{
    int comp = my_strlen(maze[0]);

    for (int i = 0; maze[i]; i++) {
        if (my_strlen(maze[i]) != comp) {
            my_putstr(LINE_NOT_EQUAL, 2);
            return (-1);
        }
    }
    return (0);
}

int solver_error_handling(char *const *maze)
{
    if (check_maze_line_size(maze) < 0)
        return (-1);
    if (check_maze_char(maze) < 0)
        return (-2);
    return (0);
}
