/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 14:19:03 by chuleung          #+#    #+#             */
/*   Updated: 2024/04/03 19:23:45 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		read_file_control(int ac, char **av, t_read_vars *read_vars)
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

void	set_up_hooks(t_vars *vars)
{
	press_key_hook(vars->win_ptr, isometric_handle_key, vars);
	mlx_mouse_hook(vars->win_ptr, mouse_button, vars);
}

int		main(int ac, char **av)
{
	t_read_vars	read_vars;
	char		**all_lines;
	t_int_strs	all_strs;
	t_vertex	*vertex_arr;
	t_vars		vars;

	if (read_file_control(ac, av, &read_vars))
		return (1);
	all_lines = extract_line(read_vars.fd, read_vars.wid);
	input_mgt(&all_strs, all_lines, read_vars.wid);
	vertex_arr = vertex_create(&all_strs, read_vars.wid, &vars);
	populate_vertexes_in_map(&vars, vertex_arr); //scale the verterice with coord that fits into the map
	vars.vertex_arr = vertex_arr;
	while(vertex_arr[1] < vars

/*
	window_handle(&vars);
	transform_all_vertexes(&vars, mx_iso4x4()); //iso matrix * the coord of each vertex;
	ortho_model(&vars);
	put_image_to_window_vars(&vars);
	set_up_hooks(&vars);
	mlx_loop(vars.mlx_ptr);
	window_close(&vars, vertex_arr, &all_strs, read_vars.fd);
	return (0);
}
*/

/*
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
		printf("%d out of %d\n", (i + 1), nbr_of_vertex);
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
*/

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