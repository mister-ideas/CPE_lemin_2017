/*
** EPITECH PROJECT, 2018
** Lem-in
** File description:
** parsing.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"
#include "lem_in.h"

char *next_data(char *cur_data)
{
	cur_data = get_next_line(0);
	if (cur_data[0] == '#' && cur_data[1] != '#')
		cur_data = get_next_line(0);
	return (cur_data);
}

int check_start_end(anthil_t *anthil, char *cur_data, int start, int end)
{
	if (start == 1) {
		anthil->start = get_names(anthil, cur_data, 1);
		if (anthil->start == NULL)
			return (84);
		start = 0;
	}
	else if (end == 1) {
		anthil->end = get_names(anthil, cur_data, 1);
		if (anthil->end == NULL)
			return (84);
		end = 0;
	}
	return (0);
}

int parsing_loop(anthil_t *anthil, char *cur_data)
{
	int start = 0;
	int end = 0;

	next_data(cur_data);
	if (cur_data == NULL)
		return (84);
	if (my_str_isnum(cur_data) == 0)
		return (84);
	anthil->nb_ants = my_getnbr(cur_data);
	while (cur_data != NULL) {
		next_data(cur_data);
		if (check_start_end(anthil, cur_data, start, end) == 84)
			return (84);
		if (detect_commands(anthil, cur_data, start, end) == 84)
			return (84);
	}
	return (0);
}

int parsing_init(void)
{
	anthil_t *anthil = malloc(sizeof(*anthil));
	char *cur_data = NULL;

	if (anthil == NULL)
		return (84);
	anthil->rooms = rooms_list_init();
	anthil->tunnels = tunnels_list_init();
	if (anthil->rooms == NULL || anthil->tunnels == NULL)
		return (84);
	if (parsing_loop(anthil, cur_data) == 84)
		return (84);
	anthil->rooms->nb_elems = anthil->nb_rooms;
	return (0);
}
