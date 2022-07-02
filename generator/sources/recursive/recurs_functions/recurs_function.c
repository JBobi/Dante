/*
** EPITECH PROJECT, 2022
** dante
** File description:
** main_function
*/

#include "my.h"

void generate_maze(char **map, int x, int y, int dir)
{
    valid_dir_t valid_dir = get_valid_dir(map, x, y, dir);
    int available_dir = 0;
    int next_dir = 0;

    increment_case(map, x, y, valid_dir);
    valid_dir = get_valid_dir(map, x, y, dir);
    while ((available_dir = is_any_directions(valid_dir)) != 0) {
        next_dir = choose_directions(valid_dir, available_dir);
        restart_processus(map, x, y, next_dir);
        valid_dir = get_valid_dir(map, x, y, dir);
    }
    map[y][x] = -1;
}

int recursive_generator(int ac, char **av)
{
    char **map = create_map(my_getnbr(av[1]), my_getnbr(av[2]));

    srand(time(NULL));
    if (map == NULL)
        return (EXIT_ERROR);
    generate_maze(map, 0, 0, DOWN);
    print_map(map);
    return (EXIT_SUCCESS);
}
