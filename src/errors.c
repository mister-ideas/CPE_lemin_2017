/*
** EPITECH PROJECT, 2018
** Lem-in
** File description:
** errors.c
*/

#include <stdio.h>
#include "lem_in.h"
#include "my.h"

int check_same_rooms(anthil_t *anthil, room_elem_t *p)
{
	room_elem_t *q = anthil->rooms->first;
	int error = -1;

	while (q) {
		if (p->room_name && q->room_name &&
		my_strcmp(p->room_name, q->room_name) == 0)
			error += 1;
		q = q->next;
	}
	return (error);
}

int check_room_exists(anthil_t *anthil, tunnel_elem_t *p)
{
	room_elem_t *q = anthil->rooms->first;
	int error = 2;

	while (q) {
		if (q->room_name && (my_strcmp(q->room_name, p->entrance_name)
		== 0 || my_strcmp(q->room_name, p->exit_name) == 0))
			error -= 1;
		q = q->next;
	}
	return (error);
}

int check_tunnel(anthil_t *anthil, tunnel_elem_t *p)
{
	if (p->entrance_name && p->exit_name) {
		if (check_room_exists(anthil, p) != 0)
			return (1);
	}
	return (0);
}

int check_errors(anthil_t *anthil)
{
	tunnel_elem_t *p = anthil->tunnels->first;

	while (p) {
		if (check_tunnel(anthil, p) == 1)
			return (1);
		tunnel_display(p);
		p = p->next;
	}
	return (0);
}
