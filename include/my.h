/*
** EPITECH PROJECT, 2017
** Library
** File description:
** my.h
*/

#ifndef MY_H_
#define MY_H_

#define READ_SIZE (1)

void my_putchar(char c);
void my_putstr(char const *str);

int my_strlen(char const *str);
int my_put_nbr(int nb);
int my_getnbr(char const *str);
int my_str_isnum(char const *str);

char *my_strcat(char *dest, char const *src);
char *get_next_line(int fd);

#endif
