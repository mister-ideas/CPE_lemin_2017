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
       
	if (ac > 1)
		return (84);
	anthil = malloc(sizeof(*anthil));
	if (anthil == NULL)
		return (84);
	if (parsing_init(anthil) == 84)
		return (84);
	room_elem_t *ptr = anthil->rooms->first;
		for(int i = 0;i < anthil->rooms->nb_elems;i++){
			printf("%d %s\n",ptr->room_nbr,ptr->room_name);
			ptr =  ptr->next;
		}
		tunnel_elem_t *ptrtunnel = anthil->tunnels->first; 
		while(ptrtunnel != NULL){
			printf("tunnel %s %s \n",ptrtunnel->entrance_name,ptrtunnel->exit_name);
			ptr =findroom(ptrtunnel->entrance_name,anthil);
			int entrer = ptr->room_nbr; 
			ptr = findroom(ptrtunnel->exit_name,anthil);
			int sortie = ptr->room_nbr;
			printf("entrer =%d sortie =  %d\n",entrer,sortie);
			ptrtunnel = ptrtunnel->next;
		}
		
		tabmap =  init_tab(anthil);
	return (0);
}
