/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 16:20:47 by chuleung          #+#    #+#             */
/*   Updated: 2025/07/17 17:50:08 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

#define KEYS_SIZE 65536
static int keys_pressed[KEYS_SIZE] = {0};

int key_press(int keycode, t_vars *vars)
{
    if (keycode >= 0 && keycode < KEYS_SIZE)
        keys_pressed[keycode] = 1;
    if (keycode == XK_Escape && vars && vars->mlx_ptr)
        mlx_loop_end(vars->mlx_ptr);
    return (0);
}

int key_release(int keycode, t_vars *vars)
{
    if (keycode >= 0 && keycode < KEYS_SIZE)
        keys_pressed[keycode] = 0;
    return (0);
}

int continuous_update(t_vars *vars)
{
    int needs_redraw = 0;

    // Defensive checks to avoid segfaults
    if (!vars || !vars->mlx_ptr || !vars->win_ptr || !vars->vertex_arr)
        return (0);

    // Move with arrow keys
    if (keys_pressed[XK_Left])  { translate(vars, XK_Left); needs_redraw = 1; }
    if (keys_pressed[XK_Right]) { translate(vars, XK_Right); needs_redraw = 1; }
    if (keys_pressed[XK_Up])    { translate(vars, XK_Up); needs_redraw = 1; }
    if (keys_pressed[XK_Down])  { translate(vars, XK_Down); needs_redraw = 1; }

    // Rotate with q/e/w/s/a/d
    if (keys_pressed[XK_q]) { rotate(vars, XK_q); needs_redraw = 1; }
    if (keys_pressed[XK_e]) { rotate(vars, XK_e); needs_redraw = 1; }
    if (keys_pressed[XK_w]) { rotate(vars, XK_w); needs_redraw = 1; }
    if (keys_pressed[XK_s]) { rotate(vars, XK_s); needs_redraw = 1; }
    if (keys_pressed[XK_a]) { rotate(vars, XK_a); needs_redraw = 1; }
    if (keys_pressed[XK_d]) { rotate(vars, XK_d); needs_redraw = 1; }

    // Zoom with i/o
    if (keys_pressed[XK_i]) { scale(vars, XK_i); needs_redraw = 1; }
    if (keys_pressed[XK_o]) { scale(vars, XK_o); needs_redraw = 1; }

    // Only redraw if something changed
    if (needs_redraw)
    {
        mlx_clear_window(vars->mlx_ptr, vars->win_ptr);
        ortho_model(vars);
        put_image_to_window_vars(vars);
    }
    return (0);
}

int iso_mouse_button(int button, int x, int y, t_vars *vars)
{
    (void)x;
    (void)y;
    if (button == Button4 || button == Button5)
        scale(vars, button);
    return (0);
}

// int	iso_kb_key(int key, t_vars *vars)
// {
// 	printf("%d pressed\n", key);
// 	if (key == XK_Escape)
// 		mlx_loop_end(vars->mlx_ptr);
// 	else if (key == XK_Left || key == XK_Right || key == XK_Up
// 		|| key == XK_Down)
// 		translate(vars, key);
// 	else if (key == XK_i || key == XK_o || key == Button4 || key == Button5)
// 		scale(vars, key);
// 	else if (key == XK_q || key == XK_e || key == XK_w || key == XK_s
// 		|| key == XK_a || key == XK_d)
// 		rotate(vars, key);
// 	return (0);
// }

// int	iso_mouse_button(int button, int x, int y, t_vars *vars)
// {
// 	x += 0;
// 	y += 0;
// 	printf("%d pressed\n", button);
// 	if (button == Button4 || button == Button5)
// 		scale(vars, button);
// 	return (0);
// }
