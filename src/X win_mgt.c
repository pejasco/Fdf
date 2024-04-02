/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    win_mgt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 16:32:48 by chuleung          #+#    #+#             */
/*   Updated: 2024/03/28 18:09:58 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	supa_pixel_put(t_img *img_vars, t_px_corrd *coord, int color)
{
	int				offset;
	unsigned char	*dst;

	if (coord->x >= WIDTH || coord->x < 0 || coord->y >= HEIGHT || coord->y < 0)
		return ;
	offset = (img_vars->line_len * coord->y) + (coord->x * (img_vars->bits_per_pixel / 8));
	*((unsigned int *)(offset + img_vars->img_pixels_ptr)) = color;
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
	for (int y = 0; y < 500; ++y)
	{
		for (int x = 0; x < 500; ++x)
		{
			supa_pixel_put(&mlx->img_vars, x, y, color);
			printf("haha");
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
		mlx_loop_end(mlx->mlx_ptr);
	}
	mlx_put_image_to_window(mlx->mlx_ptr, 
							mlx->win_ptr, 
							mlx->img_vars.img_ptr, 
							0, 0);
	return (0);
}

void	color_screen(t_mlx_data *mlx, int color)
{
	for (int y = 0; y < 200; ++y)	
	{
		for (int x = 0; x < 500; ++x)
		{
			/*
			 * This function is much faster than the library one🏻
			 * 	~Buffer in the image and push only when ready-> No flickering effect
			*/
			supa_pixel_put(&mlx->img_vars,
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
int	f(int keysym, t_mlx_data *mlx)
{

	if (keysym == XK_r)
	{
		color_screen(mlx, 0xff0000);
	}
	else if (keysym == XK_g)
	{
		color_screen(mlx, 0xff00);
	}
	else if (keysym == XK_b)
	{
		color_screen(mlx, 0xff);
	}	
	else if (keysym == XK_Escape)
		exit(1);

	// push the READY image to window
	// the last parameters are the offset image-window
	mlx_put_image_to_window(mlx->mlx_ptr,
							mlx->win_ptr, 
							mlx->img_vars.img_ptr, 
							0, 0);

	return 0;
}