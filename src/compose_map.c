/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compose_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 10:22:46 by chuleung          #+#    #+#             */
/*   Updated: 2024/04/04 11:17:55 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_mx	point_real_coord(double x, double y, double z)
{
	t_mx	point;

	point = (t_mx){.row_num = 4, .col_num = 1, .entries = {{x}, {y}, {z}, {1}}};
	return (point);
}

void populate_vertexes_in_map(t_vars *vars, t_vertex *vertex_arr)
{
	int         col;
	int         row;
	double      init_scale;
	t_vertex    *temp;

	init_scale = 50;
	row = 0;
	while (row < vars->map.row_num)
	{
		col = 0;
		while (col < vars->map.col_num)
		{
			temp = &(vertex_arr[col + row * vars->map.col_num]);
			temp->real_coord = point_real_coord(
				init_scale * col,
				init_scale * temp->z,
				-init_scale * (vars->map.row_num - row - 1));
			col++;
		}
		row++;
	}
}