/*
** EPITECH PROJECT, 2017
** Library
** File description:
** my_str_isnum.c
*/

int my_str_isnum(char const *str)
{
	int i = 0;

	while (str[i]) {
		if (str[i] >= '0' && str[i] <= '9')
			i += 1;
		else
			return (0);
	}
	return (1);
}
