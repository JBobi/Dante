/*
** EPITECH PROJECT, 2022
** dante
** File description:
** tests_get_valid_dir
*/

#include "unit_tests.h"

Test(get_valid_dir, test_up)
{
    valid_dir_t valid_dir;

    char **no_up = create_map(1, 1);
    valid_dir = get_valid_dir(no_up, 0, 0, DOWN);
    cr_assert(valid_dir.up == -1);
    my_free_word_array(no_up);

    char **dir = create_map(1, 2);
    valid_dir = get_valid_dir(dir, 0, 1, DOWN);
    cr_assert(valid_dir.up == -2);
    my_free_word_array(dir);

    char **path = create_map(1, 2);
    path[0][0] = -1;
    valid_dir = get_valid_dir(path, 0, 1, LEFT);
    cr_assert(valid_dir.up == -3);
    my_free_word_array(path);

    char **wall = create_map(1, 2);
    wall[0][0] = 2;
    valid_dir = get_valid_dir(wall, 0, 1, LEFT);
    cr_assert(valid_dir.up == -3);
    my_free_word_array(wall);

    char **valid = create_map(1, 2);
    valid_dir = get_valid_dir(valid, 0, 1, UP);
    cr_assert(valid_dir.up == 1);
    my_free_word_array(valid);
}

Test(get_valid_dir, test_right)
{
    valid_dir_t valid_dir;

    char **no_right = create_map(1, 1);
    valid_dir = get_valid_dir(no_right, 0, 0, UP);
    cr_assert(valid_dir.right == -1);
    my_free_word_array(no_right);

    char **dir = create_map(2, 1);
    valid_dir = get_valid_dir(dir, 0, 0, LEFT);
    cr_assert(valid_dir.right == -2);
    my_free_word_array(dir);

    char **path = create_map(2, 1);
    path[0][1] = -1;
    valid_dir = get_valid_dir(path, 0, 0, UP);
    cr_assert(valid_dir.right == -3);
    my_free_word_array(path);

    char **wall = create_map(2, 1);
    wall[0][1] = 2;
    valid_dir = get_valid_dir(wall, 0, 0, UP);
    cr_assert(valid_dir.right == -3);
    my_free_word_array(wall);

    char **valid = create_map(2, 1);
    valid[0][1] = 1;
    valid_dir = get_valid_dir(valid, 0, 0, RIGHT);
    cr_assert(valid_dir.right == 1);
    my_free_word_array(valid);
}

Test(get_valid_dir, test_down)
{
    valid_dir_t valid_dir;

    char **no_down = create_map(1, 1);
    valid_dir = get_valid_dir(no_down, 0, 0, LEFT);
    cr_assert(valid_dir.down == -1);
    my_free_word_array(no_down);

    char **dir = create_map(1, 2);
    valid_dir = get_valid_dir(dir, 0, 0, UP);
    cr_assert(valid_dir.down == -2);
    my_free_word_array(dir);

    char **path = create_map(1, 2);
    path[1][0] = -1;
    valid_dir = get_valid_dir(path, 0, 0, LEFT);
    cr_assert(valid_dir.down == -3);
    my_free_word_array(path);

    char **wall = create_map(1, 2);
    wall[1][0] = 2;
    valid_dir = get_valid_dir(wall, 0, 0, LEFT);
    cr_assert(valid_dir.down == -3);
    my_free_word_array(wall);

    char **valid = create_map(1, 2);
    valid_dir = get_valid_dir(valid, 0, 0, LEFT);
    cr_assert(valid_dir.down == 1);
    free(valid);
}

Test(get_valid_dir, test_left)
{
    valid_dir_t valid_dir;

    char **no_left = create_map(1, 1);
    valid_dir = get_valid_dir(no_left, 0, 0, UP);
    cr_assert(valid_dir.left == -1);
    my_free_word_array(no_left);

    char **dir = create_map(2, 1);
    valid_dir = get_valid_dir(dir, 1, 0, RIGHT);
    cr_assert(valid_dir.left == -2);
    my_free_word_array(dir);

    char **path = create_map(2, 1);
    path[0][0] = -1;
    valid_dir = get_valid_dir(path, 1, 0, UP);
    cr_assert(valid_dir.left == -3);
    my_free_word_array(path);

    char **wall = create_map(2, 1);
    wall[0][0] = 2;
    valid_dir = get_valid_dir(wall, 1, 0, UP);
    cr_assert(valid_dir.left == -3);
    my_free_word_array(wall);

    char **valid = create_map(2, 1);
    valid[0][0] = 1;
    valid_dir = get_valid_dir(valid, 1, 0, UP);
    cr_assert(valid_dir.left == 1);
    my_free_word_array(valid);
}

Test(get_valid_dir, global_test)
{
    valid_dir_t valid_dir;

    char **map = create_map(2, 3);

    map[0][0] = 2;
    valid_dir = get_valid_dir(map, 0, 1, UP);
    cr_assert(valid_dir.left == -1);
    cr_assert(valid_dir.down == -2);
    cr_assert(valid_dir.up == -3);
    cr_assert(valid_dir.right == 1);
    my_free_word_array(map);
}
