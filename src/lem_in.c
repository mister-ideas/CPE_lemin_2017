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
	char **tabmap;
	if (ac > 1)
		return (84);
	anthil = malloc(sizeof(*anthil));
	if (anthil == NULL)
		return (84);
	if (parsing_init(anthil) == 84)
		return (84);
	tabmap =  init_tab(anthil);
	return (0);
}
