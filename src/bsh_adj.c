/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsh_adj.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 18:37:36 by chuleung          #+#    #+#             */
/*   Updated: 2024/03/27 19:58:02 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	bsh_scen1_adj(t_vertex *start, t_vertex *end, t_vertex *current, t_bsh_vars *vars)
{
	if (vars->x1_lar_than_x2)
	{
		(vars->start_temp).y = -(vars->start_temp).y;
		(vars->end_temp).y = -(vars->end_temp).y;
	}
	else if (!(vars->x1_lar_than_x2))
	{
		(vars->start_temp).y = -(vars->start_temp).y;
		(vars->end_temp).y = -(vars->end_temp).y;
	}
	bsh_algo1(start, end, current, vars);
}

void	bsh_scen2_adj(t_vertex *start, t_vertex *end, t_vertex *current, t_bsh_vars *vars)
{
	int		start_temp_x_dummy;
	int 	start_temp_y_dummy;
	int 	end_temp_x_dummy;
	int 	end_temp_y_dummy;

	start_temp_x_dummy = (vars->start_temp).x;
	start_temp_y_dummy = (vars->start_temp).y;
	end_temp_x_dummy = (vars->end_temp).x;
	end_temp_y_dummy = (vars->end_temp).y;
	if (vars->x1_lar_than_x2)
	{
		(vars->start_temp).x = end_temp_y_dummy;
		(vars->start_temp).y = end_temp_x_dummy;
		(vars->end_temp).x = start_temp_y_dummy;
		(vars->end_temp).y = start_temp_x_dummy;
	}
	else if (!(vars->x1_lar_than_x2))
	{
		(vars->start_temp).x = start_temp_y_dummy;
		(vars->start_temp).y = start_temp_x_dummy;
		(vars->end_temp).x = end_temp_y_dummy;
		(vars->end_temp).y = end_temp_x_dummy;
	}
	bsh_algo2(start, end, current, vars);
}