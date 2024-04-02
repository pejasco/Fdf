/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 16:20:47 by chuleung          #+#    #+#             */
/*   Updated: 2024/04/02 23:14:32 by chuleung         ###   ########.fr       */
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
	else if (key == XK_i || key == XK_o)
		scale(vars, key);
	else if (key == XK_q || key == XK_e || key == XK_w || key == XK_s
		|| key == XK_a || key == XK_d)
		rotate(vars, key);
}

int	mouse_button(int button, t_vars *vars)
{
	printf("%d pressed\n", button);
	if (button == Button4 || button == Button5)
		scale(vars, button);
}





void	keyboard_event(XEvent event, t_vars *vars)
{
	printf("%d pressed\n", event.xkey.keycode);
	if (event.xkey.keycode == XK_Escape)
		destroy_exit(vars);
	else if (event.xkey.keycode == XK_Left || event.xkey.keycode == XK_Right || event.xkey.keycode == XK_Up
			|| event.xkey.keycode == XK_Down)
		translate(vars, event.xkey.keycode);
	else if (event.xkey.keycode == XK_i || event.xkey.keycode == XK_o)
		scale(vars, event.xkey.keycode);
	else if (event.xkey.keycode == XK_q || event.xkey.keycode == XK_e || event.xkey.keycode == XK_w || event.xkey.keycode == XK_s
			|| event.xkey.keycode == XK_a || event.xkey.keycode == XK_d)
		rotate(vars, event.xkey.keycode);
}

void	mouse_event(XEvent event, t_vars *vars)
{
	if (event.xbutton.button == Button4)  // Scroll up
	{
		printf("Scroll up\n");
		scale(vars, XK_i);  // Zoom in
	}
	else if (event.xbutton.button == Button5)  // Scroll down
	{
		printf("Scroll down\n");
		scale(vars, XK_o);  // Zoom out
	}
}

void	isometric_handle_event(XEvent event, t_vars *vars)
{
	if (event.type == KeyPress)
		keyboard_event(event, vars);
	else if (event.type == ButtonPress)
		mouse_event(event, vars);
}

