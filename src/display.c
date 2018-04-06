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
		if ((anthil->start && p->room_name) &&
		my_strcmp(p->room_name, anthil->start) == 0)
			my_putstr("##start\n");
		if ((anthil->end && p->room_name) &&
		my_strcmp(p->room_name, anthil->end) == 0)
			my_putstr("##end\n");
		if (p->line) {
			my_putstr(p->line);
			my_putchar('\n');
		}
		p = p->next;
	}
}

void tunnel_display(tunnel_elem_t *p)
{
	if (p->entrance_name && p->exit_name) {
		my_putstr(p->entrance_name);
		my_putchar('-');
		my_putstr(p->exit_name);
		my_putchar('\n');
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

void moves_display(anthil_t *anthil, path_t *path)
{
	int *nb = malloc(sizeof(int) * anthil->nb_ants);

	if (nb == NULL)
		return;
	for (int index = 0; index < anthil->nb_ants; index ++)
		nb[index] = 1;
	while (path->printed < anthil->nb_ants)
		print_ant(anthil, path, &nb);
}

int initial_display(anthil_t *anthil)
{
	my_putstr("#number_of_ants\n");
	my_put_nbr(anthil->nb_ants);
	my_putchar('\n');
	if (anthil->nb_rooms != 0) {
		rooms_display(anthil);
		if (anthil->nb_tunnels == 0)
			return (1);
		my_putstr("#tunnels\n");
		if (check_errors(anthil) > 0)
			return (1);
	} else
		return (1);
	return (0);
}
