/*
** EPITECH PROJECT, 2018
** Library
** File description:
** get_next_line.c
*/

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include "my.h"

char *get_next_line(int fd)
{
	char *line;
	char *got;
	char *buff;
	char *temp;

	if (fd < 0)
		return (NULL);
	got = malloc(sizeof(char) * READ_SIZE + 1);
	if (!got)
		return (NULL);
	buff = malloc(sizeof(char) * READ_SIZE + 1);
	if (!buff)
		return (NULL);
	while (read(fd, buff, READ_SIZE) != 0) {
		temp = malloc(sizeof(char) * my_strlen(got) + 1);
		if (!temp)
			return (NULL);
		my_strcat(temp, got);
		got = malloc(sizeof(char) * my_strlen(temp) + READ_SIZE + 1);
		if (!got)
			return (NULL);
		my_strcat(got, temp);
		free(temp);
		my_strcat(got, buff);
		for (int i = 0; buff[i]; i++) {
			if (buff[i] == '\n') {
				line = malloc(sizeof(char) *
				my_strlen(got) + 1);
				if (!line)
					return (NULL);
				for (int i = 0; got[i] != '\n'; i++)
					line[i] = got[i];
				free(got);
				return (line);
			}
		}
	}
	return (NULL);
}
