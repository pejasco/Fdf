/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ortho_render.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 22:43:34 by chuleung          #+#    #+#             */
/*   Updated: 2024/04/05 15:37:26 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_px_coord	ortho_raster_coord_with_color(t_vars *vars,
	t_vertex *vertex_arr, int row_index, int col_index)
{
	t_px_coord	pixel;
	t_vertex	vertex;

	vertex = vertex_arr[col_index + row_index * vars->map.col_num];
	pixel = raster_coord(ortho_screen_coord(vertex.real_coord));
	pixel.RGB = vertex.RGB;
	return (pixel);
}

void	ortho_draw_col2col(t_vars *vars, int row_index, int col_index)
{
	draw_line(&vars->img_vars,
		ortho_raster_coord_with_color(vars, vars->vertex_arr,
			row_index, col_index),
		ortho_raster_coord_with_color(vars, vars->vertex_arr,
			row_index, col_index + 1));
}

void	ortho_draw_row2row(t_vars *vars, int row_index, int col_index)
{
	draw_line(&vars->img_vars,
		ortho_raster_coord_with_color(vars, vars->vertex_arr,
			row_index, col_index),
		ortho_raster_coord_with_color(vars, vars->vertex_arr,
			row_index + 1, col_index));
}

void	ortho_model(t_vars *vars)
{
	int		row_index;
	int		col_index;

	row_index = 0;
	while (row_index < vars->map.row_num)
	{
		col_index = 0;
		while (col_index < vars->map.col_num)
		{
			if (col_index != vars->map.col_num - 1)
				ortho_draw_col2col(vars, row_index, col_index);
			if (row_index != vars->map.row_num - 1)
				ortho_draw_row2row(vars, row_index, col_index);
			col_index++;
		}
		row_index++;
	}
}
