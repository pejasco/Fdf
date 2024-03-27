/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsh_adj.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 18:37:36 by chuleung          #+#    #+#             */
/*   Updated: 2024/03/27 23:20:40 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	bsh_scen1_adj(t_vertex *start, t_vertex *end, t_vertex *current, t_bsh_vars *vars)
{
	if (vars->x1_lar_than_x2)
	{
		(vars->start_temp).y = -(vars->start_temp).y;
		(vars->end_temp).y = -(vars->end_temp).y;
		(vars->current_temp).y = -(vars->current_temp).y;
	}
	else if (!(vars->x1_lar_than_x2))
	{
		(vars->start_temp).y = -(vars->start_temp).y;
		(vars->end_temp).y = -(vars->end_temp).y;
		(vars->current_temp).y = -(vars->current_temp).y;
	}
	vars->delta_x = (vars->end_temp).x - (vars->start_temp).x;
	vars->delta_y = (vars->end_temp).y - (vars->start_temp).y;
	vars->next_decis_para = (2 * vars->delta_y) - vars->delta_x;
	bsh_algo1(start, end, current, vars);
}

void	bsh_scen2_adj(t_vertex *start, t_vertex *end, t_vertex *current, t_bsh_vars *vars)
{

	vars->start_temp_x_dummy = (vars->start_temp).x;
	vars->start_temp_y_dummy = (vars->start_temp).y;
	vars->end_temp_x_dummy = (vars->end_temp).x;
	vars->end_temp_y_dummy = (vars->end_temp).y;
	vars->cur_temp_x_dummy = (vars->current_temp).x;
	vars->cur_temp_y_dummy = (vars->current_temp).y;
	if (vars->x1_lar_than_x2)
	{
		(vars->start_temp).x = vars->start_temp_y_dummy;
		(vars->start_temp).y = vars->start_temp_x_dummy;
		(vars->end_temp).x = vars->end_temp_y_dummy;
		(vars->end_temp).y = vars->end_temp_x_dummy;
		(vars->current_temp).x = vars->cur_temp_y_dummy;;//not sure
		(vars->current_temp).y = vars->cur_temp_x_dummy;//not sure
	}
	else if (!(vars->x1_lar_than_x2))
	{
		(vars->start_temp).x = vars->start_temp_y_dummy;
		(vars->start_temp).y = vars->start_temp_x_dummy;
		(vars->end_temp).x = vars->end_temp_y_dummy;
		(vars->end_temp).y = vars->end_temp_x_dummy;
		(vars->current_temp).x = vars->cur_temp_y_dummy;
		(vars->current_temp).y = vars->cur_temp_x_dummy;
	}
	vars->delta_x = (vars->end_temp).x - (vars->start_temp).x;
	vars->delta_y = (vars->end_temp).y - (vars->start_temp).y;
	vars->next_decis_para = (2 * vars->delta_y) - vars->delta_x;
	bsh_algo2(start, end, current, vars);
}