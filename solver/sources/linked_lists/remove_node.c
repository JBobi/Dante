/*
** EPITECH PROJECT, 2022
** dante
** File description:
** remove_node
*/

#include "my.h"

static llist_t *remove_first_node(llist_t *list)
{
    list = list->next;
    return (list);
}

llist_t *remove_node(llist_t *list, const int x, const int y)
{
    llist_t *temp = list;
    llist_t *to_free = NULL;

    if (list == NULL)
        return (NULL);
    if (list->x == x && list->y == y)
        return (remove_first_node(list));
    while (temp && temp->next) {
        if (temp->next->x == x && temp->next->y == y) {
            to_free = temp->next;
            temp->next = to_free->next;
            return (list);
        }
        temp = temp->next;
    }
    return (list);
}
