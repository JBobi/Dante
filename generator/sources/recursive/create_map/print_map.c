/*
** EPITECH PROJECT, 2022
** dante
** File description:
** print_map
*/

#include "my.h"

void change_char(char **map)
{
    int j = 0;

    for (int i = 0; map[i]; i++) {
        for (j = 0; map[i][j] != LINE_END; j++)
            map[i][j] = (map[i][j] == -1 ? '*' : 'X');
        map[i][j] = 0;
    }
}

void print_map(char **map)
{
    int i = 0;

    change_char(map);
    for (; map[i + 1]; i++) {
        my_putstr(map[i], 1);
        my_putchar('\n');
    }
    my_putstr(map[i], 1);
    my_free_word_array(map);
}
