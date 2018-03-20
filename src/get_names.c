/*
** EPITECH PROJECT, 2018
** Lem-in
** File description:
** get_names.c
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"
#include "lem_in.h"

void get_start_end_names(char *cur_data, char *name1)
{
	int i;

	for (i = 0; cur_data[i] != ' '; i++)
		name1[i] = cur_data[i];
	name1[i] = '\0';
}

void get_room_name(anthil_t *anthil, char *cur_data, char *name1)
{
	int i;

	for (i = 0; cur_data[i] != ' '; i++)
		name1[i] = cur_data[i];
	name1[i] = '\0';
	rooms_list_insert(anthil->rooms, name1);
}

void get_tunnel_names(anthil_t *anthil, char *cur_data,
		char *name1, char *name2)
{
	int index = 0;
	int i;

	for (i = 0; cur_data[i]; i++) {
		if (cur_data[i] == '-')
			index = i;
	}
	for (i = 0; cur_data[i]; i++) {
		if (i < index)
			name1[i] = cur_data[i];
		if (i > index)
			name2[i] = cur_data[i];
	}
	name1[index] = '\0';
	name2[i] = '\0';
	tunnels_list_insert(anthil->tunnels, name1, name2);
}

char *get_names(anthil_t *anthil, char *cur_data, int mode)
{
	char *name1 = malloc(sizeof(char) * my_strlen(cur_data));
	char *name2 = malloc(sizeof(char) * my_strlen(cur_data));

	if (name1 == NULL || name2 == NULL)
		return (NULL);
	switch (mode) {
	case 1:
		get_start_end_names(cur_data, name1);
		break;
	case 2:
		get_room_name(anthil, cur_data, name1);
		break;
	case 3:
		get_tunnel_names(anthil, cur_data, name1, name2);
		break;
	}
	return (name1);
}
