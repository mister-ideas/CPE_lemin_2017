/*
** EPITECH PROJECT, 2018
** Lem-in
** File description:
** display.c
*/

#include <stdlib.h>
#include "my.h"
#include "lem_in.h"

void rooms_display(anthil_t *anthil)
{
	room_elem_t *p = anthil->rooms->first;

	my_putstr("#rooms\n");
	while (p) {
		if (p->room_name == anthil->start)
			my_putstr("##start\n");
		else if (p->room_name == anthil->end)
			my_putstr("##end\n");
		if (p->line) {
			my_putstr(p->line);
			my_putchar('\n');
		}
		p = p->next;
	}
}

void tunnels_display(anthil_t *anthil)
{
	tunnel_elem_t *p = anthil->tunnels->first;

	my_putstr("#tunnels\n");
	while (p) {
		if (p->entrance_name && p->exit_name) {
			my_putstr(p->entrance_name);
			my_putchar('-');
			my_putstr(p->exit_name);
			my_putchar('\n');
		}
		p = p->next;
	}
}

void print_ant(anthil_t *anthil, path_t *path, int **nb)
{
	char *room = NULL;

	for (int i = path->min_val; i < path->max_val; i++) {
		if (i > (path->min_val))
			my_putchar(' ');
		my_putchar('P');
		my_put_nbr(i);
		my_putchar('-');
		room = which_name(anthil, path, (*nb)[i - 1]);
		if (room)
			my_putstr(room);
		(*nb)[i - 1] += 1;
	}
	my_putchar('\n');
	if (path->max_val <= anthil->nb_ants)
		path->max_val++;
}

void move_display(anthil_t *anthil, path_t *path)
{
	int *nb = malloc(sizeof(int) * anthil->nb_ants);

	if (nb == NULL)
		return;
	for (int index = 0; index < anthil->nb_ants; index ++)
		nb[index] = 1;
	while (path->printed < anthil->nb_ants) {
		print_ant(anthil, path, &nb);
	}
}

void initial_display(anthil_t *anthil)
{
	my_putstr("#number_of_ants\n");
	my_put_nbr(anthil->nb_ants);
	my_putchar('\n');
	rooms_display(anthil);
	tunnels_display(anthil);
	my_putstr("#moves\n");
}
