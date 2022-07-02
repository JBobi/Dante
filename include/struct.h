/*
** EPITECH PROJECT, 2022
** Lib
** File description:
** struct
*/

#ifndef STRUCT_H_
    #define STRUCT_H_

    enum direction {
        UP = 0,
        RIGHT,
        DOWN,
        LEFT,
    };

    typedef struct valid_dir_s {
        int up;
        int right;
        int down;
        int left;
    } valid_dir_t;

    typedef struct stmap_s {
        char **map;
        int x;
        int y;
    } stmap_t;

    typedef struct llist_s {
        int x;
        int y;
        int path_len;
        int heuristic;
        struct llist_s *parent;
        struct llist_s *next;
    } llist_t;

    typedef struct control_list_s {
        struct llist_s *open_list;
        struct llist_s *closed_list;
    } control_list_t;

#endif /* !STRUCT_H_ */
