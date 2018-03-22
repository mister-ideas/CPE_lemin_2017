/*
** EPITECH PROJECT, 2017
** Library
** File description:
** my_strlen.c
*/

#include <stdio.h>

int my_strlen(char const *str)
{
	int i = 0;

	if (str == NULL)
		return (0);
	while (str[i])
		i++;
	return (i);
}
