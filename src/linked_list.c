/*
** EPITECH PROJECT, 2018
** Lem-in
** File description:
** linked_list.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

rooms_t *rooms_list_init(void)
{
        rooms_t *list = malloc(sizeof(*list));
        list->first = NULL;
        return (list);
}
tunnels_t *tunnels_list_init(void)
{
        tunnels_t *list = malloc(sizeof(*list));
        list->first = NULL;
        return (list);
}

int rooms_list_insert(rooms_t *list, char *room, char *line)
{
	room_elem_t *new = malloc(sizeof(*new));
	

	if (list == NULL || new == NULL)
		return (84);
	new->room_name = room;
	new->line = line;
	new->next = list->first;
	list->first = new;
	new->room_nbr = list->nb_elems;
	list->nb_elems += 1;
	return (0);
}

int tunnels_list_insert(tunnels_t *list, char *entrance, char *exit)
{
        tunnel_elem_t *new = malloc(sizeof(*new));

        if (list == NULL || new == NULL)
		return (84);
        new->entrance_name = entrance;
        new->exit_name = exit;
        new->next = list->first;
	list->first = new;
        return (0);
}
