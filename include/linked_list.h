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
	room_elem_t *next;
};

typedef struct rooms
{
	room_elem_t *first;
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
} tunnels_t;

rooms_t *init_rooms_list();
tunnels_t *init_tunnels_list();

int rooms_list_insert(rooms_t *list, char *room);
int tunnels_list_insert(tunnels_t *list, char *entrance, char *exit);

#endif
