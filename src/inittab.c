/*
** EPITECH PROJECT, 2018
** inittab
** File description:
** initab.c
*/
int inittab(anthil_t *anthil)
{
	char **tabmap;
        tabmap = malloc(sizeof(char *) * anthil->nb_rooms + 2);
        for(int i = 0;i < anthil->nb_rooms + 2;i++){
                tabmap[i] = malloc(sizeof(char) * (anthil->nb_rooms + 3));
                 tabmap[i][anthil->nb_rooms + 2] = '\0';
        }
	for(int i = 0;i < anthil->nb_rooms;i++){
                for(int j = 0;j < anthil->nb_rooms;j++){
                        //if(i == sx[0].ordre && j == sx[0].tunnel-1 || i == sx[1].ordre && j == sx[1].tunnel-1 || i == sx[2].ordre && j == sx[2].tunnel-1)
			// tabmap[i][j] = '1';
                        //else
                                tabmap[i][j] = '0';
                }
        }
        for(int i = 0;i < anthil->nb_rooms;i++)
        printf("%s\n",tabmap[i]);

}
