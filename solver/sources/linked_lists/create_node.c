/*
** EPITECH PROJECT, 2022
** dante
** File description:
** create_node
*/

#include "my.h"

llist_t *create_node(int x, int y, int path_len, int heuristic)
{
    llist_t *node = malloc(sizeof(struct llist_s));

    if (node == NULL)
        return (NULL);
    node->x = x;
    node->y = y;
    node->path_len = path_len;
    node->heuristic = heuristic;
    node->parent = NULL;
    node->next = NULL;
    return (node);
}
