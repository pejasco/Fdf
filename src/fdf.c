/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 14:19:03 by chuleung          #+#    #+#             */
/*   Updated: 2024/04/05 14:58:48 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	read_file_control(int ac, char **av, t_read_vars *read_vars)
{
	read_vars->fd = read_file(av[1]);
	read_vars->wid = 0;
	if (ac != 2 || (read_vars->fd == -1))
	{
		printf("Incorrect Input!");
		return (1);
	}
	read_vars->wid = find_wid(read_vars->fd);
	close(read_vars->fd);
	read_vars->fd = read_file(av[1]);
	if (read_vars->fd == -1)
		return (1);
	return (0);
}

void	set_up_hooks(t_vars *vars)
{
	press_key_hook(vars->win_ptr, iso_kb_key, vars);
	mlx_mouse_hook(vars->win_ptr, iso_mouse_button, vars);
}

int	main(int ac, char **av)
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
	put_vertexes_into_map(&vars, vertex_arr);
	vars.vertex_arr = vertex_arr;
	window_handle(&vars);
	transform_all_vertexes(&vars, mx_iso4x4());
	ortho_model(&vars);
	put_image_to_window_vars(&vars);
	set_up_hooks(&vars);
	mlx_loop(vars.mlx_ptr);
	window_close(&vars, vertex_arr, &all_strs, read_vars.fd);
	return (0);
}
