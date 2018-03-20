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

int parsing(void);

#endif
