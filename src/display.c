/*
** EPITECH PROJECT, 2018
** Lem-in
** File description:
** display.c
*/

#include "my.h"
#include "lem_in.h"

int initial_display(anthil_t *anthil)
{
	my_putstr("#number_of_ants\n");
	my_put_nbr(anthil->nb_ants);
	my_putchar('\n');
	my_putstr("#rooms\n");
	return (0);
}
