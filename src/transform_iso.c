/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_iso.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 16:05:25 by chuleung          #+#    #+#             */
/*   Updated: 2024/04/01 17:49:04 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_mx	mx_iso4x4(void)
{
	t_mx	iso_proj;
		iso_proj = mtxa_mult_mtxb(rot_mx_4x4_x(35.264 * PI / 180),
			rot_mx_4x4_y(-45 * PI / 180));
	return (iso_proj);
}
