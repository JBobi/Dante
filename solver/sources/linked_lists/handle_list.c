/*
** EPITECH PROJECT, 2022
** dante
** File description:
** pushfront
*/

#include "my.h"

void free_list(llist_t *list)
{
    llist_t *temp = NULL;

    while (list) {
        temp = list;
        list = list->next;
        free(temp);
    }
}

llist_t *search_node(llist_t *list, const int x, const int y)
{
    llist_t *temp = list;

    while (temp) {
        if (temp->x == x && temp->y == y)
            return (temp);
        temp = temp->next;
    }
    return (NULL);
}

llist_t *get_smallest_heuristic(llist_t *list)
{
    llist_t *temp = list;

    while (list) {
        if (temp->heuristic > list->heuristic)
            temp = list;
        list = list->next;
    }
    return (temp);
}

llist_t *pushfront(llist_t *node, llist_t *list)
{
    if (list != NULL)
        node->next = list;
    list = node;
    return (list);
}
