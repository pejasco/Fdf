/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 14:19:03 by chuleung          #+#    #+#             */
/*   Updated: 2024/03/23 00:22:10 by chuleung         ###   ########.fr       */
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

void	window_handle(t_mlx_data *mlx)
{
	//void	*diu;

	//diu = mlx_init();
	mlx->x_lib = mlx_init();
	printf("mlx_init: %p\n", mlx->x_lib);
	mlx->win = mlx_new_window(mlx->x_lib, SIDE_LEN, SIDE_LEN, "!!!!! FDF !!!!!");
	printf("mlx_new_window: %p\n", mlx->x_lib);
	mlx->img.img_ptr = mlx_new_image(mlx->x_lib, SIDE_LEN, SIDE_LEN);
	printf("mlx_new_image: %p\n", mlx->x_lib);
	mlx->img.img_pixels_ptr = mlx_get_data_addr(mlx->img.img_ptr,
												&mlx->img.bits_per_pixel,
												&mlx->img.line_len,
												&mlx->img.endian);
	printf("mlx_get_data_addr: %p\n", mlx->x_lib);
	printf("Line_len %d <-> SIDE_LEN %d\n"
			"bpp %d\n"
			"endian %d\n", mlx->img.line_len, SIDE_LEN, 
			mlx->img.bits_per_pixel, mlx->img.endian);
	
}

/*
int		main(int ac, char **av)
{
	t_read_vars	read_vars;
	char		**all_lines;
	t_int_strs	all_strs;
	t_vertex	*all_vertex;
	t_mlx_data	window;
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
	
	window.x_lib = mlx_init();
	window.win = mlx_new_window(window.x_lib, SIDE_LEN, SIDE_LEN, "!!!!! FDF !!!!!");
	window.img.img_ptr = mlx_new_image(window.x_lib, SIDE_LEN, SIDE_LEN);
	window.img.img_pixels_ptr = mlx_get_data_addr(window.img.img_ptr,
												&window.img.bits_per_pixel,
												&window.img.line_len,
												&window.img.endian);
	printf("Line_len %d <-> SIDE_LEN %d\n"
			"bpp %d\n"
			"endian %d\n", window.img.line_len, SIDE_LEN, 
			window.img.bits_per_pixel, window.img.endian);
	window_handle(&window);
	draw_dot(window.x_lib, all_vertex);
	mlx_key_hook(window.win, to_do_list, &window);
	mlx_loop(window.x_lib);
	free(all_vertex);
	free_stru(&all_strs);
	printf("main--: %p\n", window.x_lib);
	mlx_destroy_image(window.x_lib, window.img.img_ptr);
	mlx_destroy_window(window.x_lib, window.win);
	mlx_destroy_display(window.x_lib);
	free(window.x_lib);
	close(read_vars.fd);
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
	//free(all_vertex);
	free_stru(&all_strs);
	close(read_vars.fd);
	return (0);
}
*/