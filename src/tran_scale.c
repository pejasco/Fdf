/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tran_scale.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 10:17:18 by chuleung          #+#    #+#             */
/*   Updated: 2024/04/03 10:18:35 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_mx	create_scale4x4(double scale)
{
	t_mx	scale4x4;

	scale4x4 = (t_mx){
		.row_num = 4,
		.col_num = 4,
		.entries = {
	{scale, 0, 0, 0},
	{0, scale, 0, 0},
	{0, 0, scale, 0},
	{0, 0, 0, 1}}};
	return (scale4x4);
}
