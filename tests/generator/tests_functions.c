/*
** EPITECH PROJECT, 2022
** dante
** File description:
** tests_functions
*/

#include "unit_tests.h"

int comp_int_array(int *to_compare, int *comparator)
{
    for (int i = 0; to_compare[i] != LINE_END; i++)
        if (to_compare[i] != comparator[i])
            return (-1);
    return (0);
}

int comp_int_word_array(int **to_compare, int **comparator)
{
    for (int i = 0; to_compare[i]; i++)
        if (comp_int_array(to_compare[i], comparator[i]) < 0)
            return (-1);
    return (0);
}
