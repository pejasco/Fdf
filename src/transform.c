/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 14:25:13 by chuleung          #+#    #+#             */
/*   Updated: 2024/03/28 16:24:09 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	transform_all_vertexes(t_vertex *vertexes, int total, t_mx transform)
{
	int	i;

	i = 0;
	while (i < total)
	{
		vertexes[i].real_coord = mxa_mult_mxb(transform,
				vertexes[i].real_coord);
		i++;
	}
}