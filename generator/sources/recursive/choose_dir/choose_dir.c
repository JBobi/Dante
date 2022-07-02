/*
** EPITECH PROJECT, 2022
** dante
** File description:
** choose_dir
*/

#include "my.h"

int *collect_dir(valid_dir_t valid_dir, int available_dir)
{
    int *dir = malloc(sizeof(int) * available_dir);
    int i = 0;

    if (dir == NULL)
        return (NULL);
    if (valid_dir.up == 1) {
        dir[i] = UP;
        i += 1;
    }
    if (valid_dir.right == 1) {
        dir[i] = RIGHT;
        i += 1;
    }
    if (valid_dir.down == 1) {
        dir[i] = DOWN;
        i += 1;
    }
    if (valid_dir.left == 1)
        dir[i] = LEFT;
    return (dir);
}

int choose_directions(valid_dir_t valid_dir, int available_dir)
{
    int *dir = collect_dir(valid_dir, available_dir);
    int random = 0;
    int to_return = 0;

    if (dir == NULL)
        exit(EXIT_ERROR);
    random = rand() % available_dir;
    to_return = dir[random];
    free(dir);
    return (to_return);
}
