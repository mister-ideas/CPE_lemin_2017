/*
** EPITECH PROJECT, 2018
** my_path.c
** File description:
** de
*/

#include <stdio.h>
#include <stdlib.h>
#include "lem_in.h"
#include "my.h"

path_t *my_rea(path_t *path)
{
	int *tmp;

	path->max += 10;
	tmp = malloc(sizeof(int) * path->max);
	if (tmp == NULL)
		return (NULL);
	for (int i = 0; i < path->actual; i++)
		tmp[i] = path->hist[i];
	free(path->hist);
	path->hist = tmp;
	return (path);
}

char *which_name(anthil_t *anthil, path_t *path, int nb)
{
	int i = 0;
	room_elem_t *tmp = anthil->rooms->first->next;

	for (; i < (path->hist[nb]); i++) {
		if (tmp->next != NULL)
			tmp = tmp->next;
		else
			return (NULL);
	}
	if (my_strcmp(tmp->room_name, anthil->end) == 0) {
		path->min_val++;
		path->printed++;
	}
	return (tmp->room_name);
}

path_t *init_path(path_t *path)
{
	if (path == NULL)
		return (NULL);
	path->max = 20;
	path->hist = malloc(sizeof(int) * path->max);
	path->actual = 0;
	path->printed = 0;
	path->min_val = 1;
	path->max_val = 2;
	return (path);
}
