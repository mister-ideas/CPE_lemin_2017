/*
** EPITECH PROJECT, 2018
** init_tab
** File description:
** init_tab.c
*/

#include <stdlib.h>
#include <stdio.h>
#include "lem_in.h"
char *findnamemo(int indice,anthil_t *anthil)
{
        room_elem_t *ptr = anthil->rooms->first;
        for(int i = 0;i < anthil->rooms->nb_elems;i++){
                if(indice == ptr->room_nbr)
                        return (ptr->room_name);
                ptr =  ptr->next;
	}
        return (84);
}

void affichage(int *tabmove,int taille,anthil_t *anthil,int *path)
{
	for(int i =  anthil->nb_ants  + anthil->lg_path - 1;i >= anthil->nb_ants;i--) {
		if(tabmove[i] != 0)
			printf(" P%d-%s",tabmove[i],findnamemo(path[i - anthil->nb_ants + 1],anthil));
	}
	printf("\n");
}

void moveshift(int *path,int taille)
{
	for(int i = taille - 2;i >= 0;i--) {
                path[i+1] = path[i];
	}
	path[0] = 0;
}

void move(int *path,anthil_t *anthil)
{
	int taille = (anthil->nb_ants - 1) * 2 + anthil->lg_path + 1;
	int *tabmove = malloc(sizeof(int) * taille);
	
	for(int i = 0;i < taille;i++)
		tabmove[i] = 0;
	for(int i = 0;i < anthil->nb_ants;i++)
		tabmove[i] = anthil->nb_ants - i;
	for(int i = 0;i < anthil->lg_path + anthil->nb_ants -1;i++){
		moveshift(tabmove,taille);
		affichage(tabmove,taille,anthil,path);
		//for(int ii = 0;ii < taille;ii++)
		//	printf("%d ",tabmove[ii]);
		//printf("\n");
	}
}


room_elem_t *findroom(char * name,anthil_t *anthil)
{
        room_elem_t *ptr = anthil->rooms->first;
        for(int i = 0;i < anthil->rooms->nb_elems;i++){
                if(strcmp(name,ptr->room_name) == 0)
                        return (ptr);
                ptr =  ptr->next;
        }
        return (84);
}

void addtunnel(anthil_t *anthil,char **tabmap)
{
	tunnel_elem_t *ptrtunnel = anthil->tunnels->first;
	room_elem_t *ptr;
	while (ptrtunnel != NULL) {
		ptr = findroom(ptrtunnel->entrance_name,anthil);
		int entrer = ptr->room_nbr;
		ptr = findroom(ptrtunnel->exit_name,anthil);
		int sortie = ptr->room_nbr;
		printf("entrer =  %d sortie = %d\n",entrer,sortie);
		tabmap[entrer][sortie] = '1';
		tabmap[sortie][entrer] = '1';
		ptrtunnel = ptrtunnel->next;
	}
}

int *init_tab(anthil_t *anthil,int indicestart,int indiceend)
{
	char **tabmap;
	int *path;
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
	path = algotab(anthil,tabmap,indicestart,indiceend);
	for (int i = 0;i < anthil->nb_rooms;i++) {
		printf("%s\n",tabmap[i]);
	}
	return (path);
}

void roll(int *tabindice,int taille)
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
		roll(tabindice,taille);
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
	int *path = malloc(sizeof(int ) * 1000);
	int minimalpath = 100000;
	char **tabmap;
	int *tabpathmini = malloc(sizeof(int) * 1000);
	int indicenow = indicestart;
	int *tabindice = malloc(sizeof(int) *  anthil->nb_rooms);
	int test = 0;
	int c = 0;
	int I = 0;
	int i = 0;
	int chemin = 0;
	for(int i = 0;i < anthil->nb_rooms;i++){
		tabindice[i] = i;
	}
	for(int boucle = 0;boucle < 150;boucle++) {
		tabmap =  coptab(tabmap0,anthil);
		for(int i = 0;i <  anthil->nb_rooms;i++)
			printf("%s\n",tabmap0[i]);
		
		indicenow = indicestart;
		c = 0;
		I = 0;
		i = 0;
		chemin = 0;
		modiftabindice(tabindice,anthil);
		printf("\n");
		while (indiceend != indicenow) {
			if(i == anthil->nb_rooms){
				c--;
			     
				if(c == -1)
					break;
				indicenow = path[c];
				printf("indicenow = %d\n",indicenow);
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
		printf("chemin = %d path = %d \n",chemin,minimalpath);
		
		if(chemin < minimalpath){
			minimalpath = chemin;
			int a;
			for(a = 0;a < chemin;a++)
				tabpathmini[a] = path[a]; 
			tabpathmini[a] = indiceend;
		}
		
	}
	test++;
	//if(test == 1)
	//	minimalpath = chemin;
	//if(chemin < minimalpath)
	//	minimalpath = chemin;
	printf(" chemin %d\n",chemin);
	printf(" minimalpath = %d\n",minimalpath);
	
	printf("indice end  =%d\n",indiceend);
	printf("start =%s\n",anthil->start);
	for(int i = 0;i!= minimalpath + 1;i++)
		printf("%d\n",tabpathmini[i]);
	printf("end = %s\n",anthil->end);
	printf("end algo = %d\n",indicenow);
	anthil->lg_path = minimalpath;
	return (tabpathmini);
}

