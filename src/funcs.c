/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 13:41:37 by chuleung          #+#    #+#             */
/*   Updated: 2024/04/02 13:49:07 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_mx	pxcoord_to_mx(t_px_coord px_coord)
{
	t_mx	mx;

	mx.col_num = 1;
	mx.row_num = 2;
	mx.entries[0][0] = (double)(px_coord.x);
	mx.entries[1][0] = (double)(px_coord.y);
	return (mx);
}

t_px_coord	mx_to_pxcoord(t_mx mx)
{
	t_px_coord	px_coord;

	px_coord.x = round_double(mx.entries[0][0]);
	px_coord.y = round_double(mx.entries[1][0]);
	return (px_coord);
}