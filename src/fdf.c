/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 14:19:03 by chuleung          #+#    #+#             */
/*   Updated: 2024/04/02 23:26:26 by chuleung         ###   ########.fr       */
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

void	window_handle(t_vars *vars)
{
	vars->mlx_ptr = mlx_init(); //V
	vars->win_ptr = mlx_new_window(vars->mlx_ptr, WIDTH, HEIGHT, "^-^!!!FDF!!!^-^"); //V
	vars->img_vars.img_ptr = mlx_new_image(vars->mlx_ptr, WIDTH, HEIGHT); //V
	vars->img_vars.img_pixels_ptr = mlx_get_data_addr(vars->img_vars.img_ptr,
												&vars->img_vars.bits_per_pixel,
												&vars->img_vars.line_len,
												&vars->img_vars.endian); //V
}

void	window_close(t_vars *vars, t_vertex *vertex_arr, 
	t_int_strs *all_strs, int fd)
{
	free(vertex_arr);
	free_stru(&all_strs);
	mlx_destroy_window(vars->mlx_ptr, vars->win_ptr);
	mlx_destroy_image(vars->mlx_ptr, vars->img_vars.img_ptr);
	mlx_destroy_display(vars->mlx_ptr);
	free(vars->mlx_ptr);
	close(fd); 
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
	assign_vertexes_in_map(&vars, vertex_arr);
	window_handle(&vars);
	transform_all_vertexes(&vars, vertex_arr, mx_iso4x4());
	ortho_model(&vars, vertex_arr);


	set_up_hooks(&vars);
	mlx_loop(vars.mlx_ptr);
	windlow_close(vars, all_strs, vertex_arr, read_vars.fd);
	return (0);
}

static void	set_up_hooks(t_vars *vars)
{
	press_key_hook(vars->win_ptr, isometric_handle_key, vars);
	mlx_mouse_hook(vars->win_ptr, mouse_button, vars);
}







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