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
	while (ptrtunnel != NULL) {
		ptr = findroom(ptrtunnel->entrance_name,anthil);
		int entrer = ptr->room_nbr;
		ptr = findroom(ptrtunnel->exit_name,anthil);
		int sortie = ptr->room_nbr;
		tabmap[entrer][sortie] = '1';
		tabmap[sortie][entrer] = '1';
		ptrtunnel = ptrtunnel->next;
	}
}

char **init_tab(anthil_t *anthil,int indicestart,int indiceend)
{
	char **tabmap;

	tabmap = malloc(sizeof(char *) * anthil->nb_rooms);
	for (int i = 0; i < anthil->nb_rooms; i++) {
		tabmap[i] = malloc(sizeof(char) * (anthil->nb_rooms));
		tabmap[i][anthil->nb_rooms] = '\0';
	}
	for (int i = 0;i < anthil->nb_rooms;i++) {
		for (int j = 0;j < anthil->nb_rooms;j++) {
			tabmap[i][j] = '0';
		}
	}
	addtunnel(anthil,tabmap);
	algotab(anthil,tabmap,indicestart,indiceend);
	for (int i = 0;i < anthil->nb_rooms;i++) {
		printf("%s\n",tabmap[i]);
	}
	return (tabmap);
}

char **algotab(anthil_t *anthil,char **tabmap,int indicestart,int indiceend)
{
	int *path;
	//printf(" start ====  %s\n",anthil->start);
	//printf("%d %d\n",indicestart,indiceend);
	int indicenow = indicestart;
	int c = 0;
	int i = 0;
	//printf("patate\n");
	path = malloc(sizeof(int ) * 1000);
	while (indiceend != indicenow) {
		//while(tabmap[indicenow][i] != '\0') {
		if (tabmap[indicenow][i] == '1') {
			printf("%d %d\n",indicenow,i);
			path[c] = indicenow;
				tabmap[i][indicenow] = '2';
				tabmap[indicenow][i] = '2';
				indicenow = i;
				i = 0;
				c++;
			}
		if (tabmap[indicenow][i] == '\0'){
			indicenow = path[c-1];
			c = c - 1;
			i = 0;
		}
		i++;
	}
	printf("indice end  =%d\n",indiceend);
	printf("start =%s\n",anthil->start);
	for(int i = 0;i!=10;i++)
		printf("%d\n",path[i]);
	printf("end = %s\n",anthil->end);
	printf("end algo = %d\n",indicenow);
	return (tabmap);
}
