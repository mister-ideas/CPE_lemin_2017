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
	if (cur_data == NULL)
		return (0);
	if (cur_data && cur_data[0] == '#' && cur_data[1] != '#')
		cur_data = get_next_line(0);
	return (cur_data);
}

int check_start_end(anthil_t *anthil, char *cur_data)
{
	if (anthil->is_start == 1) {
		anthil->start = get_names(anthil, cur_data, 1);
		if (anthil->start == NULL)
			return (84);
		anthil->is_start = 2;
	}
	else if (anthil->is_end == 1) {
		anthil->end = get_names(anthil, cur_data, 1);
		if (anthil->end == NULL)
			return (84);
		anthil->is_end = 2;
	}
	return (0);
}

int parsing_loop(anthil_t *anthil, char *cur_data)
{
	anthil->is_start = 0;
	anthil->is_end = 0;
	cur_data = next_data(cur_data);
	if (cur_data == NULL) {
		printf("1\n");
		return (84);
	}
	if (my_str_isnum(cur_data) == 0) {
		printf("2\n");
		return (84);
	}
	anthil->nb_ants = my_getnbr(cur_data);
	printf("%s : %d\n", "nb_ants", anthil->nb_ants);
	while (cur_data) {
		cur_data = next_data(cur_data);
		if (check_start_end(anthil, cur_data) == 84) {
			printf("3\n");
			return (84);
		}
		if (detect_commands(anthil, cur_data) == 84) {
			printf("4\n");
			return (84);
		}
	}
	return (0);
}

int parsing_init(anthil_t *anthil)
{
	char *cur_data = NULL;

	if (anthil == NULL) {
		printf("A\n");
		return (84);
	}
	anthil->rooms = rooms_list_init();
	anthil->tunnels = tunnels_list_init();
	if (anthil->rooms == NULL || anthil->tunnels == NULL) {
		printf("B\n");
		return (84);
	}
	if (parsing_loop(anthil, cur_data) == 84) {
		printf("C\n");
		return (84);
	}
	anthil->nb_rooms = anthil->rooms->nb_elems + 2;
	printf("%d", anthil->nb_rooms);
	return (0);
}
