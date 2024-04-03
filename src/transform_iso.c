/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_iso.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 16:05:25 by chuleung          #+#    #+#             */
/*   Updated: 2024/04/03 17:58:49 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_mx	mx_iso4x4(void)
{
	t_mx	iso_proj;
		iso_proj = mtxa_mult_mtxb(rot_x_mx_4x4(35.264 * PI / 180),
			rot_y_mx_4x4(-45 * PI / 180));
	return (iso_proj);
}

void	translate(t_vars *vars, int key)
{
	t_mx	transl4x4;

	transl4x4 = build_translation_matrix_for_key(key);
	transform_all_vertexes(vars, transl4x4);
	fill_image_with_color(&vars->img_vars, BLACK);
	ortho_model(vars);
	put_image_to_window_vars(vars);
}

void	scale(t_vars *vars, int key)
{
	t_mx	scale4x4;

	scale4x4 = build_scale_matrix_for_key(key);
	transform_all_vertexes(vars, scale4x4);
	fill_image_with_color(&vars->img_vars, BLACK);
	ortho_model(vars);
	put_image_to_window_vars(vars);
}

void	scale_mouse(t_vars *vars, int button)
{
	t_mx	scale4x4;

	scale4x4 = build_scale_matrix_for_key(button);
	transform_all_vertexes(vars, scale4x4);
	fill_image_with_color(&vars->img_vars, BLACK);
	ortho_model(vars);
	put_image_to_window_vars(vars);
}

void	rotate(t_vars *vars, int key)
{
	t_mx	rotate4x4;

	rotate4x4 = build_rotation_matrix_for_key(key);
	transform_all_vertexes(vars, rotate4x4);
	fill_image_with_color(&vars->img_vars, BLACK);
	ortho_model(vars);
	put_image_to_window_vars(vars);
}

