/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ortho_render.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 22:43:34 by chuleung          #+#    #+#             */
/*   Updated: 2024/04/02 23:31:01 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//Orthographic projection is a method of representing three-dimensional objects in 
//two dimensions. It is a form of parallel projection, where all the projection lines 
//are orthogonal (at a right angle) to the projection plane.

t_px_coord	ortho_raster_coord_with_color(t_vars *vars, t_vertex *vertex_arr, 
	int row_idx, int col_idx)
{
	t_px_coord	pixel;
	t_vertex	vertex;

	vertex = vertex_arr[col_idx + row_idx * vars->map.col_num];
	pixel = raster_coord(ortho_screen_coord(vertex.real_coord));
	pixel.RGB = vertex.RGB;
	return (pixel);
}

void    ortho_model(t_vars *vars, t_vertex *vertex_arr)
{
	int		row_idx;
	int		col_idx;

	row_idx = 0;
	while (row_idx < vars->map.row_num)
	{
		col_idx = 0;
		while (col_idx < vars->map.col_num - 1)
		{ 
			if (col_idx != vars->map.col_num - 1)
			{
				draw_colored_line(&vars->img_vars,
					ortho_raster_coord_with_color(vars, vertex_arr, row_idx, col_idx),
					ortho_raster_coord_with_color(vars, vertex_arr, row_idx, col_idx + 1));
			}
			if (row_idx != vars->map.row_num - 1)
			{
				draw_colored_line(&vars->img_vars,
					ortho_raster_coord_with_color(vars, vertex_arr, row_idx, col_idx),
					ortho_raster_coord_with_color(vars, vertex_arr, row_idx + 1, col_idx));
			}
			col_idx++;
		}
		row_idx++;
	}
}
