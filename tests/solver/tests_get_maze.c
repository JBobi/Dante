/*
** EPITECH PROJECT, 2022
** dante
** File description:
** tests_get_maze
*/

#include "unit_tests.h"

static int count_word_array_size(char **tab)
{
    int res = 0;

    while (tab[res])
        res += 1;
    return (res);
}


int word_array_comp(char **to_compare, char **comparator)
{
    if (count_word_array_size(to_compare) != count_word_array_size(comparator))
        return (-1);
    for (int i = 0; to_compare[i]; i++)
        if (my_strcmp(to_compare[i], comparator[i]) != 0)
            return (-2);
    return (0);
}

Test(get_maze, valid_test)
{
    char *comp[] = {"**X**", "*X**X", "*X*X*", "*****", "*X*X*", NULL};
    char **maze = get_maze(VALID_MAZE);

    cr_assert(word_array_comp(maze, comp) == 0);
    my_free_word_array(maze);
}

Test(get_maze, unvalid_case)
{
    char **no_file = get_maze(NO_FILE);
    cr_assert(no_file == NULL);
}
