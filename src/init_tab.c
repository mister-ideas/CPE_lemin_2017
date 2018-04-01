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
		tabmap[i] = malloc(sizeof(char) * (anthil->nb_rooms + 1));
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

void roll(int *tabindice,int taille,anthil_t *anthil)
{
	int c = tabindice[0];
//for(int j = 0; j < anthil->nb_rooms;j++)
	//                      printf("avant %d ",tabindice[j]);
	//      printf("\n");

	for(int i = 0;i < taille-1;i++) {
		tabindice[i] = tabindice[i+1];
	}
	tabindice[taille-1] = c;
	//for(int j = 0; j < anthil->nb_rooms;j++)
	//              printf("aprés %d ",tabindice[j]);
	//      printf("\n");

}

void modiftabindice(int * tabindice,anthil_t *anthil)
{
	int taille = anthil->nb_rooms;
	int decalage = tabindice[taille / 2] + 1;
	decalage = 1;
	for(int i = 0;i < decalage;i++) {
		roll(tabindice,taille,anthil);
	}
	int tmp = tabindice[decalage];
	tabindice[decalage] = tabindice[decalage + 1];
	tabindice[decalage + 1] = tmp;
}

char **coptab(char **tabmap,anthil_t *anthil)
{
	char **tabmapbis;
	tabmapbis = malloc(sizeof(char *) * anthil->nb_rooms*2);
        for (int i = 0; i < anthil->nb_rooms; i++) {
		tabmapbis[i] = malloc(sizeof(char) * (anthil->nb_rooms+1));
                tabmapbis[i][anthil->nb_rooms] = '\0';
        }
        for (int i = 0;i < anthil->nb_rooms;i++) {
                for (int j = 0;j < anthil->nb_rooms;j++) {
			tabmapbis[i][j] = tabmap[i][j];
                }
        }
	return tabmapbis;
}

char **algotab(anthil_t *anthil,char **tabmap0,int indicestart,int indiceend)
{
	int *path;
	char **tabmap;
	int indicenow = indicestart;
	int *tabindice = malloc(sizeof(int) *  anthil->nb_rooms);
	int c = 0;
	int I = 0;
	int i = 0;
	int chemin = 0;
	for(int i = 0;i < anthil->nb_rooms;i++){
		tabindice[i] = anthil->nb_rooms-1-i;
	}
	path = malloc(sizeof(int ) * 1000);
	for(int boucle = 0;boucle < 150;boucle++) {
		tabmap =  coptab(tabmap0,anthil);
		indicenow = indicestart;
		c = 0;
		I = 0;
		i = 0;
		chemin = 0;
		modiftabindice(tabindice,anthil);
		for(int j = 0; j < anthil->nb_rooms;j++)
			printf("%d ",tabindice[j]);
		printf("\n");
		while (indiceend != indicenow) {
			if(i == anthil->nb_rooms){
				c--;
				if(c == -1)
					break;
				indicenow = path[c];
				i = 0;
				chemin--;
			}
			I = tabindice[i];
			//while(tabmap[indicenow][i] != '\0') {
			if (tabmap[indicenow][I] == '1') {
				printf("indice if = %d %d\n",indicenow,I);
				path[c] = indicenow;
				tabmap[I][indicenow] = '2';
				tabmap[indicenow][I] = '2';
				indicenow = I;
				i = 0;
				c++;
				chemin++;
			}
			else
				i++;
		}
		printf(" chemin %d\n",chemin);
	}
	//printf("indice end  =%d\n",indiceend);
	//printf("start =%s\n",anthil->start);
	for(int i = 0;i!=10;i++)
		printf("%d\n",path[i]);
	//printf("end = %s\n",anthil->end);
	//printf("end algo = %d\n",indicenow);
	return (tabmap);
}
