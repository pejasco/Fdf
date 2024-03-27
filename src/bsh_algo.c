/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsh_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 14:49:37 by chuleung          #+#    #+#             */
/*   Updated: 2024/03/27 19:59:09 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	init_check_start_vars(t_vertex *start, t_vertex *current, t_bsh_vars *vars)
{
	vars->init_check = 1;
	if (vars->scenerio == 1)
	{
		if (start->x != ((vars->current_temp).x) && start->y != ((vars->current_temp).y))
			return (1);
	}
	else if (vars->scenerio == 2)
	{
		if (start->x != ((vars->current_temp).x) && start->y != ((vars->current_temp).y))
			return (1);
	}
	else if (vars->scenerio == 3)
	{
		if ((start->x != current->x) && (start->y != current->y))
			return (1);
	}
	return (0);
}

void draw_current(t_vertex *start, t_vertex *end, t_vertex *current, t_bsh_vars *vars)
{
	if (init_check_start_vars(start, current, vars) && (vars->init_check != 1))
		exit(1);
	if (vars->scenerio == 1)
	{
		current->x = (vars->current_temp).x;
		current->y = -((vars->current_temp).y);
		current->z = (vars->current_temp).z;
		current->RGB = (vars->current_temp).RGB;
		printf("start	: (%f, %f)\n", start->x, start->y);
		printf("current	: (%f, %f)\n", current->x, current->y);
		printf("close	: (%f, %f)\n", end->x, end->y);
	}
	else if (vars->scenerio == 2)
	{
		current->x = (vars->current_temp).y;
		current->y = (vars->current_temp).x;
		current->z = (vars->current_temp).z;
		current->RGB = (vars->current_temp).RGB;
		printf("start	: (%f, %f)\n", start->x, start->y);
		printf("current	: (%f, %f)\n", current->x, current->y);
		printf("close	: (%f, %f)\n", end->x, end->y);
	}
	else if (vars->scenerio == 3)
	{
		printf("start	: (%f, %f)\n", start->x, start->y);
		printf("current	: (%f, %f)\n", current->x, current->y);
		printf("close	: (%f, %f)\n", end->x, end->y);
	}
}

void bsh_algo1(t_vertex *start, t_vertex *end, t_vertex *current, t_bsh_vars *vars)
{
	while ((vars->current_temp).x != (vars->end_temp).x || 
		(vars->current_temp).y != (vars->end_temp).y)
	{
		if (vars->next_decis_para <= 0) // (case a)
		{
			vars->cur_decis_para = vars->next_decis_para;
			vars->next_decis_para = vars->cur_decis_para + (2 * vars->delta_y);
			(vars->current_temp).x += 1;
			printf("startX	: (%f, %f)\n", start->x, start->y);
			printf("start	: (%f, %f)\n", (vars->start_temp).x, (vars->start_temp).y);
			printf("currentX	: (%f, %f)\n", current->x, current->y);
			printf("current	: (%f, %f)\n", (vars->current_temp).x, (vars->current_temp).y);
			printf("endX	: (%f, %f)\n", end->x, end->y);
			printf("end	: (%f, %f)\n", (vars->end_temp).x, (vars->end_temp).y);
			//draw_current(start, end, current, vars);
		}
		else if (vars->next_decis_para > 0)	// (case b)
		{
			vars->cur_decis_para = vars->next_decis_para;
			vars->next_decis_para = vars->cur_decis_para + 
				(2 * (vars->delta_y - vars->delta_x));
			(vars->current_temp).x += 1;
			(vars->current_temp).y += 1;
			printf("startX	: (%f, %f)\n", start->x, start->y);
			printf("start	: (%f, %f)\n", (vars->start_temp).x, (vars->start_temp).y);
			printf("currentX	: (%f, %f)\n", current->x, current->y);
			printf("current	: (%f, %f)\n", (vars->current_temp).x, (vars->current_temp).y);
			printf("endX	: (%f, %f)\n", end->x, end->y);
			printf("end	: (%f, %f)\n", (vars->end_temp).x, (vars->end_temp).y);
			//draw_current(start, end, current, vars);
		}
	}
	return ;
}

void bsh_algo2(t_vertex *start, t_vertex *end, t_vertex *current, t_bsh_vars *vars)
{
	while ((vars->current_temp).x != (vars->end_temp).x || 
		(vars->current_temp).y != (vars->end_temp).y)
	{
		if (vars->next_decis_para <= 0) // (case a)
		{
			vars->cur_decis_para = vars->next_decis_para;
			vars->next_decis_para = vars->cur_decis_para + (2 * vars->delta_y);
			(vars->current_temp).x += 1;
			printf("startX	: (%f, %f)\n", start->x, start->y);
			printf("start	: (%f, %f)\n", (vars->start_temp).x, (vars->start_temp).y);
			printf("currentX	: (%f, %f)\n", current->x, current->y);
			printf("current	: (%f, %f)\n", (vars->current_temp).x, (vars->current_temp).y);
			printf("endX	: (%f, %f)\n", end->x, end->y);
			printf("end	: (%f, %f)\n", (vars->end_temp).x, (vars->end_temp).y);
			//draw_current(start, end, current, vars);
		}
		else if (vars->next_decis_para > 0)	// (case b)
		{
			vars->cur_decis_para = vars->next_decis_para;
			vars->next_decis_para = vars->cur_decis_para + 
				(2 * (vars->delta_y - vars->delta_x));
			(vars->current_temp).x +=1;
			(vars->current_temp).y +=1;
			printf("startX	: (%f, %f)\n", start->x, start->y);
			printf("start	: (%f, %f)\n", (vars->start_temp).x, (vars->start_temp).y);
			printf("currentX	: (%f, %f)\n", current->x, current->y);
			printf("current	: (%f, %f)\n", (vars->current_temp).x, (vars->current_temp).y);
			printf("endX	: (%f, %f)\n", end->x, end->y);
			printf("end	: (%f, %f)\n", (vars->end_temp).x, (vars->end_temp).y);
			//draw_current(start, end, current, vars);
		}
	}
	return ;
}

void bsh_algo3(t_vertex *start, t_vertex *end, t_vertex *current, t_bsh_vars *vars)
{
	while (current->x != end->x || current->y != end->y)
	{
		if (vars->next_decis_para <= 0) // (case a)
		{
			vars->cur_decis_para = vars->next_decis_para;
			vars->next_decis_para = vars->cur_decis_para + (2 * vars->delta_y);
			current->x += 1;
			printf("start	: (%f, %f)\n", start->x, start->y);
			printf("current	: (%f, %f)\n", current->x, current->y);
			printf("close	: (%f, %f)\n", end->x, end->y);
			//draw_current(start, end, current, vars);
		}
		else if (vars->next_decis_para > 0)	// (case b)
		{
			vars->cur_decis_para = vars->next_decis_para;
			vars->next_decis_para = vars->cur_decis_para + 
				(2 * (vars->delta_y - vars->delta_x));
			current->x +=1;
			current->y +=1;
			printf("start	: (%f, %f)\n", start->x, start->y);
			printf("current	: (%f, %f)\n", current->x, current->y);
			printf("close	: (%f, %f)\n", end->x, end->y);
			//draw_current(start, end, current, vars);
		}
	}
	return ;
}
