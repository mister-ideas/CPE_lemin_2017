/*
** EPITECH PROJECT, 2018
** Lem-in
** File description:
** errors.c
*/

#include "lem_in.h"

int check_same_rooms(tunnel_elem_t *p)
{
	if (p->entrance_name && p->exit_name) {
		if (p->entrance_name == p->exit_name)
			return (1);
	}
	return (0);
}

int check_room_exists(anthil_t *anthil, tunnel_elem_t *p)
{
	room_elem_t *q = anthil->rooms->first;
	int error = 2;

	while (q) {
		if (p->entrance_name == q->room_name ||
		p->entrance_name == q->room_name)
			error -= 1;
	}
	return (error);
}

int check_entrance_exit_links(anthil_t *anthil, tunnel_elem_t *p, int error)
{
	if (p->entrance_name == anthil->start ||
	p->exit_name == anthil->end)
		error -= 1;
	return (error);
}

int check_errors(anthil_t *anthil)
{
	tunnel_elem_t *p = anthil->tunnels->first;
	int error = 2;

	while (p) {
		if (check_same_rooms(p) == 1)
			return (1);
		if (check_room_exists(anthil, p) != 0)
			return (1);
		error = check_entrance_exit_links(anthil, p, error);
		p = p->next;
	}
	return (error);
}
