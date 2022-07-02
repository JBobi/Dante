/*
** EPITECH PROJECT, 2021
** lib.h
** File description:
** libmy.a header
*/

#ifndef LIB_H_
    #define LIB_H_

    /* Basic lib */
void my_putchar(char c);
int my_put_nbr(int nb);
int my_getnbr(char const *str);
int my_putstr(char const *str, int channel);
int my_strlen(char const *str);
int my_strcmp(char const *s1, char const *s2);
char **my_split(char *str, char *separator);
void my_free_word_array(char **tab);

#endif /* !LIB_H_ */
