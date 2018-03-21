/*
** EPITECH PROJECT, 2018
** Lem-in
** File description:
** detect.c
*/

#include <stdio.h>
#include "lem_in.h"

int is_start_end(anthil_t *anthil)
{
	if (anthil->is_start == 2) {
		anthil->is_start = 0;
		return (1);
	}
	if (anthil->is_end == 2) {
		anthil->is_end = 0;
		return (1);
	}
	return (0);
}

int detect_type(anthil_t *anthil, char *cur_data)
{
	int tunnel = 0;

	if (is_start_end(anthil) == 1)
		return (0);
	for (int i = 0; cur_data[i]; i++) {
		if (cur_data[i] == '-')
			tunnel = 1;
	}
	if (tunnel == 1) {
		if (get_names(anthil, cur_data, 3) == NULL)
			return (84);
	} else if (tunnel == 0) {
		if (get_names(anthil, cur_data, 2) == NULL)
			return (84);
	}
	return (0);
}

int detect_commands(anthil_t *anthil, char *cur_data)
{
	if (cur_data[0] == '#' && cur_data[1] == '#' && cur_data[2] == 's'
	&& cur_data[3] == 't' && cur_data[4] == 'a' && cur_data[5] == 'r'
	&& cur_data[6] == 't' && cur_data[7] == '\0')
		anthil->is_start = 1;
	else if (cur_data[0] == '#' && cur_data[1] == '#' && cur_data[2] == 'e'
	&& cur_data[3] == 'n' && cur_data[4] == 'd'
	&& cur_data[5] == '\0')
		anthil->is_end = 1;
	else {
		if (detect_type(anthil, cur_data) == 84)
			return (84);
	}
	return (0);
}
