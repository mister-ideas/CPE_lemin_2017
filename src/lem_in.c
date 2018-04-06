/*
** EPITECH PROJECT, 2018
** Lem-in
** File description:
** lem_in.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "lem_in.h"

int main(int ac, char **av)
{
	anthil_t *anthil;

	if (ac > 1)
		return (84);
	anthil = malloc(sizeof(*anthil));
	if (anthil == NULL)
		return (84);
	if (parsing(anthil) == 84)
		return (84);
	return (0);
}
