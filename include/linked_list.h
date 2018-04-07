/*
** EPITECH PROJECT, 2018
** Lem-in
** File description:
** linked_list.h
*/

#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

typedef struct room_elem room_elem_t;
struct room_elem
{
	char *room_name;
	char *line;
	room_elem_t *next;
	int room_nbr;
};

typedef struct rooms
{
	room_elem_t *first;
	int nb_elems;
} rooms_t;

typedef struct tunnel_elem tunnel_elem_t;
struct tunnel_elem
{
	char *entrance_name;
	char *exit_name;
	tunnel_elem_t *next;
};

typedef struct tunnels
{
	tunnel_elem_t *first;
	int nb_elems;
} tunnels_t;

rooms_t *rooms_list_init();
tunnels_t *tunnels_list_init();

int rooms_list_insert(rooms_t *list, char *room, char *line);
int tunnels_list_insert(tunnels_t *list, char *entrance, char *exit);

#endif
