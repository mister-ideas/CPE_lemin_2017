/*
** EPITECH PROJECT, 2018
** Lem-in
** File description:
** lem_in.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"
#include "lem_in.h"

int indicestartfu(anthil_t *anthil)
{
	int indicestart;
	room_elem_t *ptr = anthil->rooms->first;

	for (int i = 0; i < anthil->rooms->nb_elems + 1; i++){
		if (ptr->room_name != NULL)
			if (my_strcmp(ptr->room_name, anthil->start) == 0) {
				indicestart = ptr->room_nbr;
				break;
			}
		ptr = ptr->next;
	}
	return (indicestart);
}
int indicesendfu(anthil_t *anthil)
{
	int indiceend;
	room_elem_t *ptr = anthil->rooms->first;

	for (int i = 0; i < anthil->rooms->nb_elems + 1; i++){
		if (ptr->room_name != NULL)
			if (my_strcmp(ptr->room_name, anthil->end)== 0 ){
				indiceend = ptr->room_nbr;
				break;
			}
		ptr =  ptr->next;
	}
	return (indiceend);
}

int main(int ac, char **av)
{
	anthil_t *anthil;
	int indicestart = 0;
	int indiceend = 0;

	if (ac > 1)
		return (84);
	anthil = malloc(sizeof(*anthil));
	if (anthil == NULL)
		return (84);
	if (parsing(anthil) == 84)
		return (84);
	indicestart = indicestartfu(anthil);
	indiceend = indicesendfu(anthil);
	if (anthil->nb_rooms > 1 && anthil->start && anthil->end)
		init_tab(anthil, indicestart, indiceend);
	else
		return (84);
	return (0);
}
