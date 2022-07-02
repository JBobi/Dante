/*
** EPITECH PROJECT, 2022
** Lib
** File description:
** main
*/

#include "../../include/my.h"

int main(int ac, char **av)
{
    if (generator_error_handling(ac, av) < 0)
        return (EXIT_ERROR);
    return (recursive_generator(ac, av));
}
