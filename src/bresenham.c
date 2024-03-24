/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 00:41:39 by chuleung          #+#    #+#             */
/*   Updated: 2024/03/24 22:08:53 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void bsh_algo(t_vertex *current, t_vertex *close, t_bsh_vars *vars)
{
	while (current->x != close->x && current->y != close->y)
	{
		if (vars->next_decis_para <= 0) // (case 1)
		{
			vars->cur_decis_para = vars->next_decis_para;
			vars->next_decis_para = vars->cur_decis_para + (2 * vars->delta_y);
			current->x += 1;
			printf("current: (%f, %f)\n close: (%f, %f)\n", 
				current->x, current->y, close->x, close->y);
		}
		else if (vars->next_decis_para > 0)	// (case 2)
		{
			vars->cur_decis_para = vars->next_decis_para;
			vars->next_decis_para = vars->cur_decis_para + 
				(2 * (vars->delta_y - vars->delta_x));
			current->x +=1;
			current->y +=1;
			printf("current	: (%f, %f)\n", current->x, current->y);
			printf("close	: (%f, %f)\n", close->x, close->y);
		}
	}
	return ;
}

void bsh(t_vertex *open, t_vertex *close)
{
	t_bsh_vars	vars;
	t_vertex	current;

	current.x = open->x;
	current.y = open->y;
	vars.delta_x = close->x - open->x;
	vars.delta_y = close->y - open->y;
	vars.next_decis_para = (2 * vars.delta_y) - vars.delta_x;
	bsh_algo(&current, close, &vars);
}

/*
int	main()
{
	t_vertex	open;
	t_vertex	close;

	open.x = 9;
	open.y = 18;
	close.x = 14;
	close.y = 22;
	bsh(&open, &close);
	return (0);
}
*/

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


