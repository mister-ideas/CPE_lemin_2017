/*
** EPITECH PROJECT, 2018
** Lem-in
** File description:
** lem_in.h
*/

#include "linked_list.h"

#ifndef LEM_IN_H_
#define LEM_IN_H_

typedef struct anthil {
	int nb_ants;
	char *start;
	char *end;
	rooms_t *rooms;
	tunnels_t *tunnels;
} anthil_t;

/* parsing.c */

int parsing_init(void);

/* get_names.c */

void get_start_end_names(char *cur_data, char *name1);
void get_room_name(anthil_t *anthil, char *cur_data, char *name1);
void get_tunnel_names(anthil_t *anthil, char *cur_data,
		char *name1, char *name2);
char *get_names(anthil_t *anthil, char *cur_data, int mode);

/* detect.c */

int detect_commands(anthil_t *anthil, char *cur_data, int start, int end);

#endif
