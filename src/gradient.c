/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gradient.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 15:15:40 by chuleung          #+#    #+#             */
/*   Updated: 2024/03/30 18:59:32 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


int gradient_RGB(double progress, int RGB_start, int RGB_end)
{
	t_argb RGB;

	if (progress < 0 || progress > 1)
		return (RGB_start);
	RGB = argb(
			(0xff),
			((1 - progress) * get_r(RGB_start) + progress * get_r(RGB_end)),
			((1 - progress) * get_g(RGB_start) + progress * get_g(RGB_end)),
			((1 - progress) * get_b(RGB_start) + progress * get_b(RGB_end)));
	return (RGB);
}
