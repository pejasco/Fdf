/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_read_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 19:29:13 by chuleung          #+#    #+#             */
/*   Updated: 2024/03/21 23:46:08 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int read_file(char *file_name)
{
	int     fd;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Incorrect file name!");
		return (-1);
	}
	return (fd);
}

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
	//printf("find-wid->Width: %d\n", width);
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
	while ((line = get_next_line(fd)))
	{
		len = ft_strlen(line);
		all_the_lines[i] = malloc(sizeof(char) * (len + 1));
		ft_strlcpy(all_the_lines[i], line, (len + 1));
		i++;
		free(line);
	}
	return (all_the_lines);
}


/*
int	main(int ac, char **av)
{
	int			fd;
	int			wid;
	char		**all_lines;
	t_int_strs	all_strs;
	int		i;
	int		j;

	i = 0;
	j = 0;
	fd = 0;
	wid = 0;
	all_lines = NULL;
	if (ac != 2 || ((fd = read_file(av[1])) == -1))
		return (1);
	wid = find_wid(fd);
	close(fd);
	if ((fd = read_file(av[1])) == -1)
    	return (1);
	all_lines = extract_line(fd, wid);
	input_mgt(&all_strs, all_lines, wid);
	while (all_strs.values_strs[i])
	{
		j = 0;
		while (j < all_strs.values_strs[i][0] + 1)
		{
			ft_printf("%d,", all_strs.values_strs[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
	ft_printf("\n\n");
	if (all_strs.rgb_strs != NULL)
	{
		i = 0;
		while (all_strs.rgb_strs[i])
		{
			j = 0;
			while (j < all_strs.rgb_strs[i][0] + 1)
			{
				ft_printf("%x,", all_strs.rgb_strs[i][j]);
				j++;
			}
			ft_printf("\n");
			i++;
		}
	}
	free_stru(&all_strs);
	close(fd);
	return (0);
}



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