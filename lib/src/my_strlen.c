/*
** EPITECH PROJECT, 2017
** Library
** File description:
** my_strlen.c
*/

int my_strlen(char const *str)
{
	int i = 0;

	while (str[i])
		i++;
	return (i);
}
