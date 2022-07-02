/*
** EPITECH PROJECT, 2022
** dante
** File description:
** error_handling
*/

#include "my.h"

int generator_error_handling(int ac, char **av)
{
    if (ac < 3) {
        my_putstr("./generator [length] [height]\n", 2);
        return (-1);
    }
    if (my_getnbr(av[1]) <= 0 || my_getnbr(av[2]) <= 0) {
        my_putstr("Length and height must be positive\n", 2);
        return (-2);
    }
    return (0);
}
