/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_iso.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 16:05:25 by chuleung          #+#    #+#             */
/*   Updated: 2025/07/17 17:51:22 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_mx	mx_iso4x4(void)
{
	t_mx	iso_proj;

	iso_proj = mtxa_mult_mtxb(rot_x_mx_4x4
			(35.264 * PI / 180),
			rot_y_mx_4x4(-45 * PI / 180));
	return (iso_proj);
}

void	translate(t_vars *vars, int key)
{
    t_mx	transl4x4;

    if (!vars || !vars->vertex_arr) {
        printf("translate: NULL pointer\n");
        return; // <-- FIXED: just return, not return (0);
    }

    // printf("translate called with key %d\n", key);
    transl4x4 = create_transl_mtx_hotkey(key);
    transform_all_vertexes(vars, transl4x4);
    fill_image_with_color(&vars->img_vars, BLACK);
    ortho_model(vars);
    put_image_to_window_vars(vars);
    // printf("translate finished\n");
}

void	scale(t_vars *vars, int key)
{
	t_mx	scale4x4;

	scale4x4 = create_scale_mtx_hotkey(key);
	transform_all_vertexes(vars, scale4x4);
	fill_image_with_color(&vars->img_vars, BLACK);
	ortho_model(vars);
	put_image_to_window_vars(vars);
}

void	rotate(t_vars *vars, int key)
{
	t_mx	rotate4x4;

	rotate4x4 = create_rotate_mtx_hotkey(key);
	transform_all_vertexes(vars, rotate4x4);
	fill_image_with_color(&vars->img_vars, BLACK);
	ortho_model(vars);
	put_image_to_window_vars(vars);
}
