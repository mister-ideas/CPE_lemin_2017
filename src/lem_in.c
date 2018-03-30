/*
** EPITECH PROJECT, 2018
** Lem-in
** File description:
** lem_in.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "lem_in.h"

int main(int ac, char **av)
{
	anthil_t *anthil;
	char **tabmap;
	int indicestart = 0;
	int indiceend = 0;
	if (ac > 1)
		return (84);
	anthil = malloc(sizeof(*anthil));
	if (anthil == NULL)
		return (84);
	if (parsing_init(anthil) == 84)
		return (84);
	room_elem_t *ptr = anthil->rooms->first;
		for(int i = 0;i < anthil->rooms->nb_elems;i++){
			//printf("%s %s\n",anthil->start,ptr->room_name);
			
			if(ptr->room_name == anthil->start){
				indicestart = ptr->room_nbr;
			}
			if(ptr->room_name == anthil->end){
				indiceend = ptr->room_nbr;
			}
			ptr =  ptr->next;
		}
		//indicestart = 0;
		//indiceend = 0;
		tunnel_elem_t *ptrtunnel = anthil->tunnels->first; 
		while(ptrtunnel != NULL){
			//printf("tunnel %s %s \n",ptrtunnel->entrance_name,ptrtunnel->exit_name);
			ptr =findroom(ptrtunnel->entrance_name,anthil);
			int entrer = ptr->room_nbr; 
			ptr = findroom(ptrtunnel->exit_name,anthil);
			int sortie = ptr->room_nbr;
			//printf("entrer =%d sortie =  %d\n",entrer,sortie);
			ptrtunnel = ptrtunnel->next;
		}
		
		tabmap =  init_tab(anthil,indicestart,indiceend);
	return (0);
}
