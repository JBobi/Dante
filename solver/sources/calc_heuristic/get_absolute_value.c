/*
** EPITECH PROJECT, 2022
** dante
** File description:
** get_absolute_value
*/

#include "my.h"

int get_absolute_value(int nbr)
{
    if (nbr < 0)
        return (nbr * (-1));
    return (nbr);
}
