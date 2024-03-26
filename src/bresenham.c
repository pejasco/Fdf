/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 00:41:39 by chuleung          #+#    #+#             */
/*   Updated: 2024/03/26 23:32:28 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	bsh_scen_admin(t_vertex *start, t_vertex *end, t_vertex *current, t_bsh_vars *vars)
{
	if (vars->scenerio == 1)
	{
		(vars->current_temp).x = current->x;
		(vars->current_temp).y = -(current->y);
		(vars->current_temp).z = current->z;
		(vars->current_temp).RGB = current->RGB;
		vars->delta_x = (vars->end_temp).x - (vars->start_temp).x;
		vars->delta_y = (vars->end_temp).y - (vars->start_temp).y;
		vars->next_decis_para = (2 * vars->delta_y) - vars->delta_x;
		bsh_algo1(start, end, current, vars);
	}
	else if (vars->scenerio == 2)
	{
		(vars->current_temp).x = current->y;
		(vars->current_temp).y = current->x;
		(vars->current_temp).z = current->z;
		(vars->current_temp).RGB = current->RGB;
		vars->delta_x = (vars->end_temp).x - (vars->start_temp).x;
		vars->delta_y = (vars->end_temp).y - (vars->start_temp).y;
		vars->next_decis_para = (2 * vars->delta_y) - vars->delta_x;
		bsh_algo2(start, end, current, vars);
	}
	else
		exit(1);
}

void	bsh_scen1(t_vertex *start, t_vertex *end, t_vertex *current, t_bsh_vars *vars)
{
	if(vars->x1_lar_than_x2)
	{
		(vars->start_temp).x = end->x;
		(vars->start_temp).y = -(end->y);
		(vars->start_temp).z = end->z;
		(vars->start_temp).RGB = end->RGB;
		(vars->end_temp).x = start->x;
		(vars->end_temp).y = -(start->y);
		(vars->end_temp).z = start->z;
		(vars->end_temp).RGB = start->RGB;
	}
	else if(!(vars->x1_lar_than_x2)) 
	{
		(vars->start_temp).x = start->x;
		(vars->start_temp).y = -(start->y);
		(vars->start_temp).z = start->z;
		(vars->start_temp).RGB = start->RGB;
		(vars->end_temp).x = end->x;
		(vars->end_temp).y = -(end->y);
		(vars->end_temp).z = end->z;
		(vars->end_temp).RGB = end->RGB;
	}
	bsh_scen_admin(start, end, current, vars);
}

void	bsh_scen2(t_vertex *start, t_vertex *end, t_vertex *current, t_bsh_vars *vars)
{
	if(vars->x1_lar_than_x2)
	{
		(vars->start_temp).x = end->y;
		(vars->start_temp).y = end->x;
		(vars->start_temp).z = end->z;
		(vars->start_temp).RGB = end->RGB;
		(vars->end_temp).x = start->y;
		(vars->end_temp).y = start->x;
		(vars->end_temp).z = start->z;
		(vars->end_temp).RGB = start->RGB;
	}
	else if(!(vars->x1_lar_than_x2)) 
	{
		(vars->start_temp).x = start->y;
		(vars->start_temp).y = start->x;
		(vars->start_temp).z = start->z;
		(vars->start_temp).RGB = start->RGB;
		(vars->end_temp).x = end->y;
		(vars->end_temp).y = end->x;
		(vars->end_temp).z = end->z;
		(vars->end_temp).RGB = end->RGB;
	}
	bsh_scen_admin(start, end, current, vars);
}

void	bsh_scen3(t_vertex *start, t_vertex *end, t_vertex *current, t_bsh_vars *vars)
{
	if(vars->x1_lar_than_x2)
	{
		vars->delta_x = start->x - end->x;
		vars->delta_y = start->y - end->y;
		vars->next_decis_para = (2 * vars->delta_y) - vars->delta_x;
	}
	else if(!(vars->x1_lar_than_x2))
	{
		vars->delta_x = end->x - start->x;
		vars->delta_y = end->y - start->y;
		vars->next_decis_para = (2 * vars->delta_y) - vars->delta_x;
	}
	bsh_algo3(start, end, current, vars);
}

void	bsh_scenerio(t_vertex *start, t_vertex *end, t_vertex *current, t_bsh_vars *vars)
{
	if (vars->slope < 0)
	{
		vars->scenerio = 1;
		bsh_scen1(start, end, current, vars);
	}
	else if (vars->slope > 1)
	{
		vars->scenerio = 2;
		bsh_scen2(start, end, current, vars);
	}
	else
	{
		vars->scenerio = 3;
		bsh_scen3(start, end, current, vars);
	}
}

void	bsh(t_vertex *start, t_vertex *end)
{
	t_bsh_vars	vars;
	t_vertex	current;

	current.x = start->x;
	current.y = start->y;
	vars.slope = (end->y - current.y) / (end->x - current.x);
	vars.x1_lar_than_x2 = 0;
	bsh_scenerio(start, end, &current, &vars);
	if (end->x < current.x)
	{
		current.x = end->x;
		current.y = end->y;
		if (start->x == current.x)
			exit(1);
		vars.slope = (start->y - current.y) / (start->x - current.x);
		vars.x1_lar_than_x2 = 1;
		bsh_scenerio(start, end, &current, &vars); //start becomes end
	}
}


/*
void		quicksort(t_stacks *stacks, t_qs_stats stats);

typedef struct s_qs_stats
{
	int		high;
	int		low;
	int		rotate;
	int		push;
	char	from;
}	t_qs_stats;

quicksort(stacks, (t_qs_stats){.low = stats->low,.high = (med - 1), .from = 'b'});
*/

/*
void bsh_algo(t_vertex *current, t_vertex *end, t_bsh_vars *vars)
{
	while (current->x != end->x && current->y != end->y)
	{
		if (vars->next_decis_para <= 0) // (case a)
		{
			vars->cur_decis_para = vars->next_decis_para;
			vars->next_decis_para = vars->cur_decis_para + (2 * vars->delta_y);
			current->x += 1;
			printf("current: (%f, %f)\n close: (%f, %f)\n", 
				current->x, current->y, end->x, end->y);
		}
		else if (vars->next_decis_para > 0)	// (case b)
		{
			vars->cur_decis_para = vars->next_decis_para;
			vars->next_decis_para = vars->cur_decis_para + 
				(2 * (vars->delta_y - vars->delta_x));
			current->x +=1;
			current->y +=1;
			printf("current	: (%f, %f)\n", current->x, current->y);
			printf("close	: (%f, %f)\n", end->x, end->y);
		}
	}
	return ;
}
*/




int	main()
{
	t_vertex	start;
	t_vertex	end;

	start.x = 14;
	start.y = 18;
	end.x = 9;
	end.y = 22;
	bsh(&start, &end);
	return (0);
}
