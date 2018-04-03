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
	room_elem_t *element = malloc(sizeof(*element));

	if (list == NULL || element == NULL)
		return (NULL);
	element->room_name = NULL;
	element->line = NULL;
	element->next = NULL;
	list->first = element;
	return (list);
}

tunnels_t *tunnels_list_init(void)
{
	tunnels_t *list = malloc(sizeof(*list));
	tunnel_elem_t *element = malloc(sizeof(*element));

	if (list == NULL || element == NULL)
		return (NULL);
	element->entrance_name = NULL;
	element->exit_name = NULL;
	element->next = NULL;
	list->first = element;
	return (list);
}

int rooms_list_insert(rooms_t *list, char *room, char *line)
{
	room_elem_t *new = malloc(sizeof(*new));
	room_elem_t *p = list->first;

	if (list == NULL || new == NULL)
		return (84);
	new->room_name = room;
	new->line = line;
	new->next = NULL;
	while (p->next)
		p = p->next;
	p->next = new;
	list->nb_elems += 1;
	new->room_nbr = list->nb_elems - 1;
	return (0);
}

int tunnels_list_insert(tunnels_t *list, char *entrance, char *exit)
{
	tunnel_elem_t *new = malloc(sizeof(*new));
	tunnel_elem_t *p = list->first;

	if (list == NULL || new == NULL)
		return (84);
	new->entrance_name = entrance;
	new->exit_name = exit;
	new->next = NULL;
	while (p->next)
		p = p->next;
	p->next = new;
	return (0);
}
