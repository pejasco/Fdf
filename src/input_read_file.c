/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_read_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 19:29:13 by chuleung          #+#    #+#             */
/*   Updated: 2024/04/05 16:18:06 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	read_file(char *file_name)
{
	int	fd;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Incorrect file name!!!");
		return (-1);
	}
	return (fd);
}

int	find_wid(int fd)
{
	char	*line;
	int		width;

	width = 0;
	line = get_next_line(fd);
	while ((line != NULL))
	{
		width++;
		free(line);
		line = get_next_line(fd);
	}
	return (width);
}

char	**extract_line(int fd, int wid)
{
	char	*line;
	char	**all_the_lines;
	int		i;
	int		len;

	i = 0;
	all_the_lines = (char **)malloc(sizeof(char *) * (wid + 1));
	all_the_lines[wid] = NULL;
	line = get_next_line(fd);
	while ((line != NULL))
	{
		len = ft_strlen(line);
		all_the_lines[i] = malloc(sizeof(char) * (len + 1));
		ft_strlcpy(all_the_lines[i], line, (len + 1));
		i++;
		free(line);
		line = get_next_line(fd);
	}
	return (all_the_lines);
}
