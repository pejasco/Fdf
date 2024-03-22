/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 14:19:03 by chuleung          #+#    #+#             */
/*   Updated: 2024/03/22 00:01:28 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	read_file_control(int ac, char **av, t_read_vars *read_vars)
{
	read_vars->fd = read_file(av[1]);
	read_vars->wid = 0;
	if (ac !=2 || (read_vars->fd == -1))
		return (1);
	read_vars->wid = find_wid(read_vars->fd);
	close(read_vars->fd);
	read_vars->fd = read_file(av[1]);
	if (read_vars->fd == -1)
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	t_read_vars	read_vars;
	char		**all_lines;
	t_int_strs	all_strs;
	t_vertex	*all_vertex;
	int			i;
	int			nbr_of_vertex;

	i = 0;
	all_lines = NULL;
	if (read_file_control(ac, av, &read_vars))
		return (1);
	all_lines = extract_line(read_vars.fd, read_vars.wid);
	input_mgt(&all_strs, all_lines, read_vars.wid);
	all_vertex = vertex_create(&all_strs, read_vars.wid);
	nbr_of_vertex = (all_strs.values_strs[0][0] * read_vars.wid); 
	while (i < nbr_of_vertex) 
	{
		printf("%d / %d\n", (i + 1), nbr_of_vertex);
		printf("%f, ", all_vertex[i].x);
		printf("%f, ", all_vertex[i].y);
		printf("%f, ", all_vertex[i].z);
		printf("%d, ", all_vertex[i].RGB);
		printf("%d, ", all_vertex[i].wid);
		printf("%d\n", all_vertex[i].len);
		i++;
	}
	free(all_vertex);
	free_stru(&all_strs);
	close(read_vars.fd);
	return (0);
}
