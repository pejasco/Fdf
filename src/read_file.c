/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 19:29:13 by chuleung          #+#    #+#             */
/*   Updated: 2024/03/10 22:30:15 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int find_width(int fd)
{
	char	*line;
	int		width;

	wid = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		width++
		free (line);
	}

}

int find_length(char *file_name)
{



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

/*#include <fcntl.h>
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