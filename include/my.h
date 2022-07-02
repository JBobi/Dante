/*
** EPITECH PROJECT, 2021
** my.h
** File description:
** project's header
*/

#ifndef MY_H_
    #define MY_H_

/* INCLUDES */
    #include <stdlib.h>
    #include <unistd.h>
    #include <stdarg.h>
    #include <time.h>
    #include <fcntl.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include "struct.h"
    #include "lib.h"

/* MACRO */
    #define EXIT_SUCCESS 0
    #define EXIT_ERROR 84
    #define LINE_END -84

    // SOLVER
    #define NO_FILE_FOUND "No file has been found\n"
    #define LINE_NOT_EQUAL "Maze must have equal size lines\n"
    #define WRONG_CHAR "Maze must only contains 'X' and '*' characters\n"

/* PROTOTYPES */
    // GENERATOR

    /* MAIN FUNCTION */

    /* RECURSIVE FUNCTION */
    int recursive_generator(int ac, char **av);
    valid_dir_t get_valid_dir(char **map, int x, int y, int dir);
    void increment_case(char **map, int x, int y, valid_dir_t valid_dir);
    int is_any_directions(valid_dir_t valid);
    int choose_directions(valid_dir_t valid_dir, int available_dir);
    void generate_maze(char **map, int x, int y, int dir);
    void restart_processus(char **map, int x, int y, int next_dir);
    void print_map(char **map);
    char **create_map(int x, int y);

    /* ERROR HANDLING */
    int generator_error_handling(int ac, char **av);

    // SOLVER

    /* MAIN FUNCTION */
    int dante_solver(int ac, char **av);
    int a_star(const stmap_t maze_info);
    valid_dir_t solver_get_valid_dir(const stmap_t maze_info,
    const llist_t *parent);
    control_list_t *handle_successor(control_list_t *control, llist_t *parent,
    stmap_t maze_info);
    void print_solved_maze(llist_t *end, stmap_t maze_info);

    /* READ_FILE */
    char **get_maze(const char *filepath);
    stmap_t solver_get_stmap(char **maze);
    void free_control_list(control_list_t *control);

    /* ERROR HANDLING */
    int solver_error_handling(char *const *maze);

    /* LINKED LIST */
    control_list_t *init_control_list(void);
    llist_t *create_node(int x, int y, int path_len, int heuristic);
    llist_t *pushfront(llist_t *node, llist_t *list);
    llist_t *get_smallest_heuristic(llist_t *list);
    void free_list(llist_t *list);
    llist_t *remove_node(llist_t *list, const int x, const int y);
    llist_t *search_node(llist_t *list, const int x, const int y);

    /* CALC HEURISTIC */
    int get_absolute_value(int nbr);
    int calc_heuristic(int x, int y, stmap_t maze, int path_len);

#endif /* !MY_H_ */
