/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 19:29:13 by chuleung          #+#    #+#             */
/*   Updated: 2024/03/13 23:49:59 by chuleung         ###   ########.fr       */
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

	}
	return (length);
}


int read_file(char *file_name)
{
	int     fd;
	char    *line;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Incorrect file name!");
		return (-1);
	}
	return (fd);
}

char	**extract_line(int fd, int wid) 
{
	char	*line;
	char	**all_the_lines;
	int		i;
	int		len;

	i = 0;
	all_the_lines = (char **)malloc(sizeof(char *) * (wid + 1));
	all_the_lines[wid] = '\0';
	while ((line = get_next_line(fd)) != NULL)
	{
		len = ft_strlen(line);
		all_the_lines[i] = malloc(sizeof(char) * (len + 1));
		ft_strlcpy(all_the_lines[i], line, (len + 1));
		i++;
		free(line);
	}
	close(fd);
	return (all_the_lines);
}


int input_status(char **all_lines)
{
	int		i;

	i = 0;
	while (all_lines[i])
	{
		if (find_comma(all_lines[i]))
			return (1);
		i++;
	}
	return (0);
}

t_int_strs *input_mgt(char **all_lines, int wid)
{
	int		i;
	t_int_strs	*all_strs;

	i = 0;
	if ((input_status(all_lines)))
	{
		


	}
	else if (!input_status(all_lines))
	{
		all_strs->


	}
	return (all_strs);
}

int	main(int ac, char **av)
{
	int		fd;
	int		wid;
	char	**all_lines;
	t_int_strs	strs;


	fd = 0;
	wid = 0;
	all_lines = NULL;
	if (ac != 2 || ((fd = read_file(av[1])) == -1))
		return (1);
	wid = find_wid(fd);
	all_lines = extract_line(fd, wid);
	input_mgt(all_lines, wid);








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


/*
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
	//line = get_next_line(fd);
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
*/