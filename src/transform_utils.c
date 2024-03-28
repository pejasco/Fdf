/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 13:47:09 by chuleung          #+#    #+#             */
/*   Updated: 2024/03/28 14:24:58 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_mx	mx_scale4x4(double scale)
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

t_mx	mx_isometric4x4(void)
{
	t_mx	iso_proj;

	iso_proj = 


}