/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 16:20:47 by chuleung          #+#    #+#             */
/*   Updated: 2024/04/04 18:44:34 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	isometric_handle_key(int key, t_vars *vars)
{
	printf("%d pressed\n", key);
	if (key == XK_Escape)
		mlx_loop_end(vars->mlx_ptr);
	else if (key == XK_Left || key == XK_Right || key == XK_Up
		|| key == XK_Down)
		translate(vars, key);
	else if (key == XK_i || key == XK_o || key == Button4 || key == Button5)
		scale(vars, key);
	else if (key == XK_q || key == XK_e || key == XK_w || key == XK_s
		|| key == XK_a || key == XK_d)
		rotate(vars, key);
	return (0);
}

int	mouse_button(int button, t_vars *vars)
{
	printf("%d pressed\n", button);
	if (button == Button4 || button == Button5)
		scale(vars, button);
	return (0);
}

int my_scroll_hook(double ydelta, t_vars *vars)
{
	if (ydelta > 0)
		scale(vars, ydelta);
	else if (ydelta < 0)
		scale(vars, ydelta);
	return (0);
}
