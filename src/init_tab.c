/*
** EPITECH PROJECT, 2018
** init_tab
** File description:
** init_tab.c
*/

#include <stdlib.h>
#include <stdio.h>
#include "lem_in.h"

char **init_tab(anthil_t *anthil)
{
	char **tabmap;
	tabmap = malloc(sizeof(char *) * anthil->nb_rooms);
	for(int i = 0; i < anthil->nb_rooms; i++){
		tabmap[i] = malloc(sizeof(char) * (anthil->nb_rooms));
		tabmap[i][anthil->nb_rooms] = '\0';
	}
	for(int i = 0;i < anthil->nb_rooms;i++){
		for(int j = 0;j < anthil->nb_rooms;j++){
			tabmap[i][j] = '0';
		}
	}
	for(int i = 0;i < anthil->nb_rooms;i++)
		printf("%s\n",tabmap[i]);
	return (tabmap);
}
