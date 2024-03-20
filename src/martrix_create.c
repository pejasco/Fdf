/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   martrix_create.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 17:47:57 by chuleung          #+#    #+#             */
/*   Updated: 2024/03/20 22:58:44 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vertex	*assign_val_to_ptr_by_row_with_color(t_mode color, int i, t_int_strs *all_strs, int wid)
{
	int			j;
	t_vertex	vertex_struc;

	j = 0;
	while (j != all_strs->values_strs[i][0])
	{
		vertex_struc.wid
		vertex_struc = all_struc->
		all_strs->values_strs;
		vRGB-> all_strs->
		if (color != With_Color)

		


		}
		j++;
	}
	return (&vertex_struc);
}


t_vertex	**assign_matrix_to_pts(t_int_strs *all_strs, int wid)
{
	int			i;
	int			j;
	t_vertex	**ptr_to_vertrx_struc;

	i = 0;
	ptr_to_struc = (t_vertex **)malloc(sizeof(t_vertex *) * (wid + 1));
	ptr_to_struc[wid] = NULL;
	if (all_strs->rgb_strs)
	{
		while (i < wid)



		{	
			j = 1;
			while (j != all_strs->values_strs[i][0])
			{
				assigning_val_by_row();
				j++;
			}
			i++;
		}
	}
	else if(!(all_strs->rgb_strs))
	{
		while
		{
			assigning_by_row(all_strs->values_strs[i][0]


		}
	
	
}