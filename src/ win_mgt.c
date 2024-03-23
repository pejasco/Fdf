/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    win_mgt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 16:32:48 by chuleung          #+#    #+#             */
/*   Updated: 2024/03/23 18:18:33 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	supa_pixel_put(t_img *img, int x, int y, int color)
{
	int	offset;

	offset = (img->line_len * y) + (x * (img->bits_per_pixel / 8));
	*((unsigned int *)(offset + img->img_pixels_ptr)) = color;
}


void	draw_dot(t_mlx_data *mlx, t_vertex *all_vertex)
{
	supa_pixel_put(&mlx->img, all_vertex->x, 
		all_vertex->y, all_vertex->RGB);
}

void	draw_line(t_mlx_data *mlx, t_vertex *all_vertex)
{
	for (int x = 0; x < 30; ++x)
	{
		supa_pixel_put(&mlx->img, all_vertex->x, 
			all_vertex->y, 0xFF0000);
	}
}

int		keys_activities(int keysym, t_mlx_data *mlx)
{
	if (keysym == XK_Escape)
		mlx_loop_end(mlx->x_lib);

	mlx_put_image_to_window(mlx->x_lib, 
							mlx->win, 
							mlx->img.img_ptr, 
							0, 0);
	return (0);
}
