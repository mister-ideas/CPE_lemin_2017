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

int get_start_end_names(anthil_t *anthil, char *cur_data, char *name1,
			char *name2)
{
	int i;
	int comment = 0;

	for (i = 0; cur_data[i] != ' '; i++)
		name1[i] = cur_data[i];
	name1[i] = '\0';
	for (i = 0; cur_data[i]; i++) {
		if (cur_data[i] == '#') {
			comment = 1;
			break;
		}
		name2[i] = cur_data[i];
	}
	if (comment == 1)
		name2[i - 1] = '\0';
	else
		name2[i] = '\0';
	if (rooms_list_insert(anthil->rooms, name1, name2) == 84)
		return (84);
	return (0);
}

int get_room_name(anthil_t *anthil, char *cur_data, char *name1, char *name2)
{
	int i;
	int comment = 0;

	for (i = 0; cur_data[i] != ' '; i++)
		name1[i] = cur_data[i];
	name1[i] = '\0';
	for (i = 0; cur_data[i]; i++) {
		if (cur_data[i] == '#') {
			comment = 1;
			break;
		}
		name2[i] = cur_data[i];
	}
	if (comment == 1)
		name2[i - 1] = '\0';
	else
		name2[i] = '\0';
	if (rooms_list_insert(anthil->rooms, name1, name2) == 84)
		return (84);
	return (0);
}

int get_tunnel_names(anthil_t *anthil, char *cur_data,
		char *name1, char *name2)
{
	int index = 0;
	int i;
	int j = 0;

	for (i = 0; cur_data[i]; i++) {
		if (cur_data[i] == '-')
			index = i;
	}
	for (i = 0; cur_data[i]; i++) {
		if (i < index)
			name1[i] = cur_data[i];
		if (i > index) {
			name2[j] = cur_data[i];
			j++;
		}
	}
	name1[index] = '\0';
	name2[my_strlen(cur_data) - index] = '\0';
	if (tunnels_list_insert(anthil->tunnels, name1, name2) == 84)
		return (84);
	return (0);
}

char *get_names(anthil_t *anthil, char *cur_data, int mode)
{
	char *name1 = malloc(sizeof(char) * my_strlen(cur_data));
	char *name2 = malloc(sizeof(char) * my_strlen(cur_data));

	if (name1 == NULL || name2 == NULL)
		return (NULL);
	switch (mode) {
	case 1:
		if (get_start_end_names(anthil, cur_data, name1, name2) == 84)
			return (NULL);
		break;
	case 2:
		if (get_room_name(anthil, cur_data, name1, name2) == 84)
			return (NULL);
		break;
	case 3:
		if (get_tunnel_names(anthil, cur_data, name1, name2) == 84)
			return (NULL);
		break;
	}
	return (name1);
}
