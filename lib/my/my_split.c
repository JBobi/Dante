/*
** EPITECH PROJECT, 2022
** mysokoban
** File description:
** my_split
*/

#include "../../include/my.h"

int is_separator(char c, char *separator)
{
    for (int i = 0; separator[i]; i++)
        if (c == separator[i])
            return (1);
    return (0);
}

int count_nb_words(char *str, char *separator)
{
    int nb = 0;

    if (is_separator(str[0], separator) == 0)
        nb += 1;
    for (int i = 1; str[i]; i++) {
        if (is_separator(str[i], separator) == 0 &&
        is_separator(str[i - 1], separator) == 1)
            nb += 1;
    }
    return (nb);
}

char *copy_words(char *str, char *separator)
{
    int size = 0;
    char *to_return = NULL;

    while (str[size] && is_separator(str[size], separator) == 0)
        size += 1;
    to_return = malloc(sizeof(char) * (size + 1));
    if (to_return == NULL)
        return (NULL);
    to_return[size] = 0;
    for (int i = 0; i < size; i++)
        to_return[i] = str[i];
    return (to_return);
}

char **create_array(char *str, char *separator, int nb_words)
{
    char **to_return = NULL;
    int pos = 0;

    to_return = malloc(sizeof(char *) * (nb_words + 1));
    if (to_return == NULL)
        return (NULL);
    for (int i = 0; i < nb_words; i++) {
        while (is_separator(str[pos], separator) == 1)
            pos += 1;
        to_return[i] = copy_words(&str[pos], separator);
        while (is_separator(str[pos], separator) == 0)
            pos += 1;
    }
    to_return[nb_words] = NULL;
    return (to_return);
}

char **my_split(char *str, char *separator)
{
    int nb_words = 0;
    char **to_return = NULL;

    if (!str[0])
        return (NULL);
    nb_words = count_nb_words(str, separator);
    if (nb_words <= 0)
        return (NULL);
    to_return = create_array(str, separator, nb_words);
    if (to_return == NULL)
        return (NULL);
    return (to_return);
}
