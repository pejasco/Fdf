/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    win_mgt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 16:32:48 by chuleung          #+#    #+#             */
/*   Updated: 2024/03/24 23:26:40 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	supa_pixel_put(t_img *img, int x, int y, int color)
{
	int	offset;

	offset = (img->line_len * y) + (x * (img->bits_per_pixel / 8));
	*((unsigned int *)(offset + img->img_pixels_ptr)) = color;
}

/*
void	draw_dot(t_mlx_data *mlx, t_vertex *all_vertex)
{
	supa_pixel_put(&mlx->img, all_vertex->x, 
		all_vertex->y, all_vertex->RGB);
}
*/

void	draw_line(t_mlx_data *mlx, int color)
{
	for (int y = 0; y < 200; ++y)
	{
		for (int x = 0; x < 500; ++x)
		{
			supa_pixel_put(&mlx->img, x, y, color);
			printf("Regina!!!");
		}
	}
}

int		keys_activities(int keysym, t_mlx_data *mlx)
{
	if (keysym == XK_r)
		draw_line(mlx, 0xffffff);
	if (keysym == XK_Escape)
	{
		//mlx_destroy_window(mlx->x_lib, mlx->win);
		//mlx_destroy_image(mlx->x_lib, mlx->img.img_ptr);
		//mlx_destroy_display(mlx->x_lib);
		mlx_loop_end(mlx->x_lib);
	}
	mlx_put_image_to_window(mlx->x_lib, 
							mlx->win, 
							mlx->img.img_ptr, 
							0, 0);
	return (0);
}

void	color_screen(t_mlx_data *data, int color)
{
	for (int y = 0; y < 200; ++y)	
	{
		for (int x = 0; x < 500; ++x)
		{
			/*
			 * This function is much faster than the library one🏻
			 * 	~Buffer in the image and push only when ready-> No flickering effect
			*/
			supa_pixel_put(&data->img,
						x, 
						y, 
						color);
		}
	}
}

/*
 * This time i plug color in hexadecimal directly
 * easy vanilla
*/
int	f(int keysym, t_mlx_data *data)
{

	if (keysym == XK_r)
	{
		color_screen(data, 0xff0000);
	}
	else if (keysym == XK_g)
	{
		color_screen(data, 0xff00);
	}
	else if (keysym == XK_b)
	{
		color_screen(data, 0xff);
	}	
	else if (keysym == XK_Escape)
		exit(1);

	// push the READY image to window
	// the last parameters are the offset image-window
	mlx_put_image_to_window(data->x_lib,
							data->win, 
							data->img.img_ptr, 
							0, 0);

	return 0;
}