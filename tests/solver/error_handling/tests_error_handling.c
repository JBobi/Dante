/*
** EPITECH PROJECT, 2022
** dante
** File description:
** tests_error_handling
*/

#include "unit_tests.h"

Test(solver_error_handling, valid_case)
{
    char **maze = get_maze(VALID_MAZE);

    cr_assert(solver_error_handling(maze) == 0);
    my_free_word_array(maze);
}

Test(solver_error_handling, different_size_lines)
{
    char **maze = get_maze(DIFFERENT_SIZE_LINE);

    cr_assert(solver_error_handling(maze) == -1);
    my_free_word_array(maze);
}

Test(solver_error_handling, wrong_char)
{
    char **maze = get_maze(WRONG_CHARACTERS);

    cr_assert(solver_error_handling(maze) == -2);
    my_free_word_array(maze);
}
