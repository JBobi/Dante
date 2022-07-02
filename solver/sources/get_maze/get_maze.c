/*
** EPITECH PROJECT, 2022
** dante
** File description:
** get_maze
*/

#include "my.h"

static char *read_file(const char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    char *buf = NULL;
    struct stat file_stat;

    if (fd <= 0) {
        my_putstr(NO_FILE_FOUND, 2);
        return (NULL);
    }
    stat(filepath, &file_stat);
    buf = malloc(sizeof(char) * (file_stat.st_size + 2));
    if (buf == NULL)
        return (NULL);
    read(fd, buf, file_stat.st_size);
    buf[file_stat.st_size] = '\n';
    buf[file_stat.st_size + 1] = 0;
    close(fd);
    return (buf);
}

char **get_maze(const char *filepath)
{
    char *map = read_file(filepath);
    char **maze = NULL;

    if (map == NULL)
        return (NULL);
    maze = my_split(map, "\n");
    if (maze == NULL)
        return (NULL);
    free(map);
    return (maze);
}
