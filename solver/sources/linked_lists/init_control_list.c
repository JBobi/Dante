/*
** EPITECH PROJECT, 2022
** dante
** File description:
** init_control_list
*/

#include "my.h"

void free_control_list(control_list_t *control)
{
    free_list(control->open_list);
    free_list(control->closed_list);
    free(control);
}

control_list_t *init_control_list(void)
{
    control_list_t *control = malloc(sizeof(struct control_list_s));

    if (control == NULL)
        return (NULL);
    control->open_list = NULL;
    control->closed_list = NULL;
    return (control);
}
