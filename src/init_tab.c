/*
** EPITECH PROJECT, 2018
** init_tab
** File description:
** init_tab.c
*/

#include <stdlib.h>
#include <stdio.h>
#include "lem_in.h"
void addtunnel(anthil_t *anthil,char **tabmap)
{
	tunnel_elem_t *ptrtunnel = anthil->tunnels->first;
	room_elem_t *ptr;
	while(ptrtunnel != NULL){
		printf("tunnel %s %s \n",ptrtunnel->entrance_name,ptrtunnel->exit_name);
		ptr = findroom(ptrtunnel->entrance_name,anthil);
		int entrer = ptr->room_nbr;
		ptr = findroom(ptrtunnel->exit_name,anthil);
		int sortie = ptr->room_nbr;
		tabmap[entrer][sortie] = '1';
		tabmap[sortie][entrer] = '1';
		ptrtunnel = ptrtunnel->next;
	}
}

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
	addtunnel(anthil,tabmap);
	for(int i = 0;i < anthil->nb_rooms;i++)
		printf("%s\n",tabmap[i]);
	return (tabmap);
}
