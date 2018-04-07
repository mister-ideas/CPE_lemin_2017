/*
** EPITECH PROJECT, 2018
** Lem-in
** File description:
** display.c
*/

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

void initial_display(anthil_t *anthil)
{
	my_putstr("#number_of_ants\n");
	my_put_nbr(anthil->nb_ants);
	my_putchar('\n');
	rooms_display(anthil);
	tunnels_display(anthil);
	my_putstr("#moves\n");
}
