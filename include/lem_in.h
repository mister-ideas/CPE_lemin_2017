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
	int nb_rooms;
	char *start;
	char *end;
	rooms_t *rooms;
	tunnels_t *tunnels;
	int is_start;
	int is_end;
} anthil_t;

/* parsing.c */
int parsing(anthil_t *anthil);

/* get_names.c */
int get_start_end_names(anthil_t *anthil, char *cur_data, char *name1,
			char *name2);
int get_room_name(anthil_t *anthil, char *cur_data, char *name1, char *name2);
int get_tunnel_names(anthil_t *anthil, char *cur_data,
		char *name1, char *name2);
char *get_names(anthil_t *anthil, char *cur_data, int mode);

/* detect.c */
int detect_commands(anthil_t *anthil, char *cur_data);

/* display.c */
void initial_display(anthil_t *anthil);

/* errors.c */
int check_errors(anthil_t *anthil);

#endif
