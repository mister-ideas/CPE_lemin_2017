/*
** EPITECH PROJECT, 2018
** Lem-in
** File description:
** init_tab.c
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"
#include "lem_in.h"

room_elem_t *findroom(char *name, anthil_t *anthil)
{
	room_elem_t *ptr = anthil->rooms->first;

	ptr = ptr->next;
	for (int i = 0; i < anthil->rooms->nb_elems; i++) {
		if (my_strcmp(name, ptr->room_name) == 0)
			return (ptr);
		ptr = ptr->next;
	}
	return (NULL);
}

void addtunnel(anthil_t *anthil, char **tabmap)
{
	tunnel_elem_t *tunnel = anthil->tunnels->first;
	room_elem_t *room;
	int entrance;
	int exit;

	while (tunnel) {
		if (tunnel->entrance_name && tunnel->exit_name) {
			room = findroom(tunnel->entrance_name, anthil);
			entrance = room->room_nbr;
			room = findroom(tunnel->exit_name, anthil);
			exit = room->room_nbr;
			tabmap[entrance][exit] = '1';
			tabmap[exit][entrance] = '1';
		}
		tunnel = tunnel->next;
	}
}

char **algotab(anthil_t *anthil, char **tabmap, int indicestart, int indiceend)
{
	int *path;
	int indicenow = indicestart;
	int c = 0;
	int i = 0;

	path = malloc(sizeof(int) * 1000);
	if (path == NULL)
		return (NULL);
	while (indiceend != indicenow) {
		if (tabmap[indicenow][i] == '1') {
			printf("%d %d\n", indicenow, i);
			path[c] = indicenow;
			tabmap[i][indicenow] = '2';
			tabmap[indicenow][i] = '2';
			indicenow = i;
			i = 0;
			c++;
		}
		if (tabmap[indicenow][i] == '\0') {
			indicenow = path[c - 1];
			c = c - 1;
			i = 0;
		}
		i++;
	}
	printf("indice end  =%d\n", indiceend);
	printf("start =%s\n", anthil->start);
	for (int i = 0; i != 10; i++)
		printf("%d\n", path[i]);
	printf("end = %s\n", anthil->end);
	printf("end algo = %d\n", indicenow);
	return (tabmap);
}

char **init_tab(anthil_t *anthil, int indicestart, int indiceend)
{
	char **tabmap;

	tabmap = malloc(sizeof(char*) * anthil->nb_rooms);
	if (tabmap == NULL)
		return (NULL);
	for (int i = 0; i < anthil->nb_rooms; i++) {
		tabmap[i] = malloc(sizeof(char) * anthil->nb_rooms + 1);
		if (tabmap[i] == NULL)
			return (NULL);
	}
	for (int i = 0; i < anthil->nb_rooms; i++) {
		for (int j = 0; j < anthil->nb_rooms; j++)
			tabmap[i][j] = '0';
		tabmap[i][anthil->nb_rooms] = '\0';
	}
	addtunnel(anthil, tabmap);
	algotab(anthil, tabmap, indicestart, indiceend);
	for (int i = 0; i < anthil->nb_rooms; i++)
		printf("%s\n", tabmap[i]);
	return (tabmap);
}
