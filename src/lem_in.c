/*
** EPITECH PROJECT, 2018
** Lem-in
** File description:
** lem_in.c
*/

#include <stdlib.h>
#include "lem_in.h"

int main(void)
{
	anthil_t *anthil;

	anthil = parsing_init();
	if (anthil == NULL)
		return (3);
	init_tab(anthil);
	return (53);
}
