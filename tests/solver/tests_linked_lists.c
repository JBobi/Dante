/*
** EPITECH PROJECT, 2022
** dante
** File description:
** tests_linked_lists
*/

#include "unit_tests.h"

Test(init_control_list, create_control_list)
{
    control_list_t *control = init_control_list();

    cr_assert(control != NULL);
    cr_assert(control->open_list == NULL);
    cr_assert(control->closed_list == NULL);
    free(control);
}

Test(create_node, create_node)
{
    llist_t *node = create_node(1, 3, 7, 53);

    cr_assert(node != NULL);
    cr_assert(node->x == 1);
    cr_assert(node->y == 3);
    cr_assert(node->path_len == 7);
    cr_assert(node->heuristic == 53);
    cr_assert(node->next == NULL);
    cr_assert(node->parent == NULL);
    free(node);
}

Test(pushfront, pushfront)
{
    llist_t *node = create_node(3, 2, 5, 43);

    llist_t *empty_list = NULL;
    empty_list = pushfront(node, empty_list);
    cr_assert(empty_list != NULL);
    cr_assert(empty_list->next == NULL);
    cr_assert(empty_list->parent == NULL);
    cr_assert(empty_list->heuristic == 43);
    cr_assert(empty_list->path_len == 5);
    cr_assert(empty_list->x == 3);
    cr_assert(empty_list->y == 2);

    llist_t *not_empty_list = create_node(7, 1, 9, 32);
    not_empty_list = pushfront(node, not_empty_list);
    cr_assert(not_empty_list->x == 3);
    cr_assert(not_empty_list->next->heuristic == 32);
    free(not_empty_list->next);

    free(node);
}

Test(get_smallest_heuristic, smallest_heuristic)
{
    llist_t *list = create_node(0, 0, 0, 42);
    llist_t *res = NULL;

    list->next = create_node(3, 5, 10, 12);
    list->next->next = create_node(1, 1, 2, 38);
    list->next->next->next = create_node(1, 2, 3, 36);

    res = get_smallest_heuristic(list);
    cr_assert(res->x == 3);
    cr_assert(res->y == 5);
    cr_assert(res->path_len == 10);
    cr_assert(res->heuristic == 12);
    free_list(list);

    llist_t *empty_list = NULL;
    res = get_smallest_heuristic(empty_list);
    cr_assert(res == NULL);
}

Test(remove_node, remove_first_node)
{
    llist_t *list = create_node(2, 1, 3, 15);

    list->next = create_node(1, 1, 2, 18);
    list->next->next = create_node(0, 1, 1, 20);
    list->next->next->next = create_node(0, 0, 0, 25);

    list = remove_node(list, 2, 1);
    cr_assert(list->x == 1);
    free_list(list);
}

Test(remove_node, remove_rand_node)
{
    llist_t *list = create_node(2, 1, 3, 15);

    list->next = create_node(1, 1, 2, 18);
    list->next->next = create_node(0, 1, 1, 20);
    list->next->next->next = create_node(0, 0, 0, 25);

    list = remove_node(list, 1, 1);
    cr_assert(list->x == 2);
    cr_assert(list->next->x == 0);
    free_list(list);
}

Test(remove_node, remove_last_node)
{
    llist_t *list = create_node(2, 1, 3, 15);

    list->next = create_node(1, 1, 2, 18);
    list->next->next = create_node(0, 1, 1, 20);
    list->next->next->next = create_node(0, 0, 0, 25);

    list = remove_node(list, 0, 0);
    cr_assert(list->x == 2);
    cr_assert(list->next->x == 1);
    cr_assert(list->next->next->next == NULL);
    free_list(list);
}

Test(remove_node, no_node_to_remove)
{
    llist_t *list = create_node(2, 1, 3, 15);

    list->next = create_node(1, 1, 2, 18);
    list->next->next = create_node(0, 1, 1, 20);
    list->next->next->next = create_node(0, 0, 0, 25);

    list = remove_node(list, 3, 1);
    cr_assert(list->x == 2);
    cr_assert(list->next->x == 1);
    cr_assert(list->next->next->x == 0);
    cr_assert(list->next->next->next->y == 0);
    cr_assert(list->next->next->next->next == NULL);
    free_list(list);
}

Test(remove_node, empty_list)
{
    llist_t *list = NULL;

    list = remove_node(list, 4, 3);
    cr_assert(list == NULL);
}

Test(search_node, in_list)
{
    llist_t *list = create_node(2, 0, 3, 43);
    llist_t *res = NULL;

    list->next = create_node(1, 0, 2, 35);
    list->next->next = create_node(1, 1, 2, 34);
    res = search_node(list, 1, 0);
    cr_assert(res->heuristic == 35);
    free_list(list);
}

Test(search_node, not_in_list)
{
    llist_t *list = create_node(2, 0, 3, 43);
    llist_t *res = NULL;

    list->next = create_node(1, 0, 2, 35);
    list->next->next = create_node(1, 1, 2, 34);
    res = search_node(list, 3, 4);
    cr_assert(res == NULL);
    free_list(list);
}

Test(search_node, empty_list)
{
    llist_t *list = NULL;
    llist_t *res = search_node(list, 3, 4);

    cr_assert(res == NULL);
}
