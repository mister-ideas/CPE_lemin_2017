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
	int nb_tunnels;
	char *start;
	char *end;
	rooms_t *rooms;
	tunnels_t *tunnels;
	int is_start;
	int is_end;
} anthil_t;

typedef struct path path_t;
struct path {
	int *hist;
	int max;
	int actual;
	int printed;
	int min_val;
	int max_val;
};

/* my_path.c */

path_t *my_rea(path_t *path);
path_t *init_path(path_t *path);
char *which_name(anthil_t * anthil, path_t *path, int nb);

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

int moves_display(anthil_t *anthil, path_t *path);
int initial_display(anthil_t *anthil);
void tunnel_display(tunnel_elem_t *p);

/* errors.c */

int check_errors(anthil_t *anthil);

/* init_tab.c  */

char **init_tab(anthil_t *anthil, int indicestart, int indiceend);

#endif
