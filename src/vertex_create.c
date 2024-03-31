/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertex_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 17:47:57 by chuleung          #+#    #+#             */
/*   Updated: 2024/03/31 18:33:52 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vertex	assign_data_to_vertex(int row, int col, int wid, t_int_strs *all_strs)
{
	t_vertex	vertex_struc;
	int			col_with_size;

	col_with_size = (int) col + 1;
	vertex_struc.x = col;
	vertex_struc.y = row;
	vertex_struc.z = all_strs->values_strs[row][col_with_size];
	vertex_struc.RGB = 0xffffff;
	if (all_strs->rgb_strs)
		vertex_struc.RGB = all_strs->rgb_strs[row][col_with_size];
	vertex_struc.wid = wid;
	vertex_struc.len = all_strs->values_strs[row][0];
	vertex_struc.real_coord.col_num = vertex_struc.len;
	vertex_struc.real_coord.col_num = vertex_struc.wid;
	return (vertex_struc);
}


t_vertex	*vertex_create(t_int_strs *all_strs, int wid, t_vars *mlx)
{
	int			row;
	int			col;
	t_vertex	*vertex_arr;

	row = 0;
	col = 0;
	(mlx->map).row_num = wid;
	if (all_strs->values_strs[0] != NULL && all_strs->values_strs != NULL)
		(mlx->map).col_num = all_strs->values_strs[0][0];
	else
		exit (1);
	vertex_arr = (t_vertex *)malloc(sizeof(t_vertex) 
		* ((wid * (mlx->map).col_num)));
	while (row < wid)
	{
		col = 0;
		while(col < (mlx->map).col_num)
		{
			vertex_arr[(mlx->map).col_num * row + col] = 
			assign_data_to_vertex(row, col, wid, all_strs);
			col++;
		}
		row++;
	}
	return (vertex_arr);
}