/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 00:41:39 by chuleung          #+#    #+#             */
/*   Updated: 2024/03/19 22:03:49 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_pix_decis bresenham_algo_2nd
	(t_coord *current, t_pix_decis last_decis, t_brese_vars *vars)
{
	while ((current->x != close->x && current.y != close->y)
		|| (i != (vars.delta_x - 1)))
	{





		
	}
	if (last_decis == E) // decis_para <= 0 (case 1)
	{
		vars->decis_para_in_E = vars->prev_decis_para + 
		(2 * vars->delta_y);
		current->x += 1;	
	}
	else if (last_decis == NE) // decis_para >0 (case 2)
	{
		vars->decis_para_in_NE = vars->prev_decis_para + 
		(2 * (vars->delta_y - vars->delta_x));
		current->x += 1;
		current->y += 1;


	}
}

int bresenham(t_coord *open, t_coord *close)
{
	t_brese_vars	vars;
	t_coord			current;

	int i;
	i = 0;
	current.x = open->x;
	current.y = open->y;
	vars.delta_x = close->x - open->x;
	vars.delta_y = close->y - open->y;
	vars.init_decis_para = (2 * vars.delta_y) - vars.delta_x;
	if (vars.init_decis_para <= 0)
		bresenham_algo_2nd(&current, E, &vars);
	else if (vars.init_decis_para > 0)
		bresenham_algo_2nd(&current, NE, &vars);
	
	
	
	//while ((current.x != close->x && current.y != close->y)
	//	|| (i != (vars.delta_x - 1)))
	{
		if (vars.init_decis_para <= 0)
		{
			
			vars.prev_decis_pa

		}
		else if (vars.init_decis_para > 0)
		{
			vars.prev_decis_para 
			vars.prev_decis_para = 
		}
		i++;
	}
	return (0);
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


