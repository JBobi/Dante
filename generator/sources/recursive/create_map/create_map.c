/*
** EPITECH PROJECT, 2022
** dante
** File description:
** create_map
*/

#include "my.h"

char *file_with_zero(char *line, int x)
{
    for (int i = 0; i < x; i++)
        line[i] = 0;
    line[x] = LINE_END;
    return (line);
}

char **create_map(int x, int y)
{
    char **map = NULL;

    map = malloc(sizeof(char *) * (y + 1));
    if (map == NULL)
        return (NULL);
    for (int i = 0; i < y; i++) {
        map[i] = malloc(sizeof(char) * (x + 1));
        if (map[i] == NULL)
            return (NULL);
        map[i] = file_with_zero(map[i], x);
    }
    map[y] = NULL;
    return (map);
}
