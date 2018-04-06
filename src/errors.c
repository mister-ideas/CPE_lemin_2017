/*
** EPITECH PROJECT, 2018
** Lem-in
** File description:
** errors.c
*/

#include <stdio.h>
#include "lem_in.h"
#include "my.h"

int check_same_rooms(tunnel_elem_t *p)
{
	if (my_strcmp(p->entrance_name, p->exit_name) == 0)
		return (1);
	return (0);
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

int check_entrance_exit_links(anthil_t *anthil, tunnel_elem_t *p, int error)
{
	if (my_strcmp(p->entrance_name, anthil->start) == 0 ||
	my_strcmp(p->entrance_name, anthil->end) == 0 ||
	my_strcmp(p->exit_name, anthil->start) == 0 ||
	my_strcmp(p->exit_name, anthil->end) == 0)
		error -= 1;
	return (error);
}

int check_errors(anthil_t *anthil)
{
	tunnel_elem_t *p = anthil->tunnels->first;
	int error = 2;

	while (p) {
		if (p->entrance_name && p->exit_name) {
			if (check_same_rooms(p) == 1)
				return (1);
			if (check_room_exists(anthil, p) != 0)
				return (1);
			error = check_entrance_exit_links(anthil, p, error);
		}
		p = p->next;
	}
	return (error);
}
