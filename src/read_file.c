/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 19:29:13 by chuleung          #+#    #+#             */
/*   Updated: 2024/03/11 21:56:04 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int find_wid(int fd)
{
	char	*line;
	int		width;

	width = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		width++;
		free(line);
	}
	return (width);
}


int find_len(int fd, int width)
{
	char	*line;
	char	**char_strs;
	int		**all_int_strs;
	int		i;
	int		j;
	int		k;
	int		no_of_char_strs_aft_spl;

	i = 0;
	j = 0;
	k = 1;
	all_int_strs = (int **)malloc(sizeof(int *) * width);
	all_int_strs[width] = NULL;
	while ((line = get_next_line(fd)) != NULL)
	{
		char_strs = ft_split(line, " ");
		no_of_char_strs_aft_spl = ft_strlen(&char_strs);
		while (i < width)
		{	
			all_int_strs[i] = (int *)malloc(sizeof(int) * ((no_of_char_strs_aft_spl + 1)));
			all_int_strs[i][0] = no_of_char_strs_aft_spl;
			while(j < no_of_char_strs_aft_spl)
			{
				all_int_strs[i][j + 1] = ft_atoi(char_strs[j]);
				j++;
			}
			i++;
		}


		strs_join[i] = ft_strjoin()




		while(strs[i])
		{
			strft_atoi
			ft_strlen(strs);
		
			
		}
		free(line)
	}
	return (length)
}


int read_file(char *file_name)
{
	int     fd;
	char    *line;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Incorrect file name!");
		return (1);
	}
	line = get_next_line(fd);
	//printf("%s", line);
	//free(line);
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free (line);
	}
	close(fd);
	return (0);
}

int main(int ac, char **av)
{
	if (ac == 2)
	{
		read_file(av[1]);


		return (1);
	}
	return (0);
}

/*
#include <fcntl.h>
#include <stdio.h>

int main(void) {
	int fd = open("file.txt", O_RDONLY);
	char *line;

	if (fd == -1) {
		printf("Failed to open file\n");
		return 1;
	}

	while ((line = get_next_line(fd)) != NULL) {
		printf("%s\n", line);
		free(line);
	}

	close(fd);

	return 0;
}
*/