/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compose_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 10:22:46 by chuleung          #+#    #+#             */
/*   Updated: 2024/04/01 00:06:58 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_mx	point_real_coord(double x, double y, double z)
{
	t_mx	point;

	point = (t_mx){.row_num = 4, .col_num = 1, .entries = {{x}, {y}, {z}, {1}}};
	return (point);
}

void assign_vertexes_in_map(t_vars *vars, t_vertex *vertex_arr)
{
	int         i;
	int         col;
	int         row;
	double      init_scale;
	t_vertex    *temp;

	init_scale = 60.0;
	row = 0;
	i = 0;
	while (row < vars->map.col_num)
	{
		col = 0;
		while (col < vars->map.col_num)
		{
			temp = &(vertex_arr[col + row * vars->map.col_num]);
			temp->real_coord = point_real_coord(
				init_scale * col,
				init_scale * vertex
	


			)

		}
		col++;
	}

}