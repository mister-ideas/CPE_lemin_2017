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


void detect_commands(char *cur_data, int start, int end)
{
	if (cur_data[0] == '#' && cur_data[1] == '#' && cur_data[2] == 's'
	    && cur_data[3] == 't' && cur_data[4] == 'a' && cur_data[5] == 'r'
	    && cur_data[6] == 't' && cur_data[7] == '\n')
		start = 1;
	else if (cur_data[0] == '#' && cur_data[1] == '#' && cur_data[2] == 'e'
		 && cur_data[3] == 'n' && cur_data[4] == 'd' && cur_data[5] == '\n')
		end = 1;
	else
		detect_type(cur_data);
}

void detect_type(char *cur_data, int start, int end)
{
	for (int i = 0; cur_data[i]; i++) {
		if (cur_data[i] == '-') {
		}			
	}
}

int parsing(void)
{
	anthil_t *anthil = malloc(sizeof(*anthil));
	char *cur_data = NULL;
	
	int start = 0;
	int end = 0;

	if (anthil == NULL)
		return (84);
	anthil->rooms = rooms_list_init();
	anthil->tunnels = tunnels_list_init();
	if (anthil->rooms == NULL || anthil->tunnels)
		return (84);
	next_data(cur_data);
	if (my_str_isnum(cur_data) == 0)
		return (84);
	anthil->nb_ants = my_getnbr(cur_data);
	while (cur_data != NULL) {
		next_data(cur_data);
		if (start == 1) {
			anthil->start = cur_data;
			start = 0;
		}
		else if (end == 1) {
			anthil->end = cur_data;
			end = 0;
		}
		detect_commands(cur_data, start, end);
	}
	return (0);
}
