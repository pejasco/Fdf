/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gradient.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 15:15:40 by chuleung          #+#    #+#             */
/*   Updated: 2024/04/05 17:50:04 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	gradient_rgb(double progress, int RGB_start, int RGB_end)
{
	t_argb	rgb;

	if (progress < 0 || progress > 1)
		return (RGB_start);
	rgb = argb(
			(0xff),
			((1 - progress) * get_r(RGB_start) + progress * get_r(RGB_end)),
			((1 - progress) * get_g(RGB_start) + progress * get_g(RGB_end)),
			((1 - progress) * get_b(RGB_start) + progress * get_b(RGB_end)));
	return (rgb);
}

void	init_gradient_rgb(t_interpolation *t, t_px_coord *a, t_px_coord *b)
{
	t->curr = 0.0;
	t->step = 1.0 / ft_abs(b->x - a->x);
}
