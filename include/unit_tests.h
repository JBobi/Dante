/*
** EPITECH PROJECT, 2022
** Lib
** File description:
** unit_tests
*/

#ifndef UNIT_TESTS_H_
    #define UNIT_TESTS_H_

    /* INCLUDES */
    #include "my.h"
    #include <criterion/criterion.h>

    /* MACROS */
    #define VALID_MAZE "../tests/solver/valid_maze"
    #define NO_FILE "no_file"

    #define DIFFERENT_SIZE_LINE \
    "../tests/solver/error_handling/different_size_lines"
    #define WRONG_CHARACTERS    \
    "../tests/solver/error_handling/wrong_char"

    /* PROTOTYPES */
    int comp_int_word_array(int **to_compare, int **comparator);
    int word_array_comp(char **to_compare, char **comparator);
#endif /* !UNIT_TESTS_H_ */
