/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Scofield <Scofield@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 00:41:39 by chuleung          #+#    #+#             */
/*   Updated: 2024/03/26 01:49:15 by Scofield         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"





void	bsh(t_vertex *start, t_vertex *end)
{
	t_bsh_vars	vars;
	t_vertex	current;

	current.x = start->x;
	current.y = start->y;
	vars.slope = (end->y - current->y) / (end->x - current->x)
	current.x1_lar_than_x2 = 0;
	if (end->x < current.x)
	{
		current.x = end->x;
		current.y = end->y;
		vars.slope = (start-,>y - current->y) / (start->x - current->x)
		currentx1_lar_than_x2 = 1;
	}
	if (slope < 0)

	else if (slope)


	else

	




}


void bsh(t_vertex *start, t_vertex *end)
{
	t_bsh_vars	vars;
	t_vertex	current;
	float		slope;
	int			scenerio;


	//normal case
	current.x = start->x;
	current.y = start->y;
	vars.delta_x = end->x - start->x;
	vars.delta_y = end->y - start->y;
	vars.next_decis_para = (2 * vars.delta_y) - vars.delta_x;
	slope =(end->y - start->y) / (end->x - start->x);
	bsh_algo_nor(&current, close, &vars);

	//case 1 (and no case 2and case 3)
	current.x = end->x;
	current.y = end->y;
	vars.delta_x = start->x - end->x;
	vars.delta_y = start->y - end->y;
	vars.next_decis_para = (2 * vars.delta_y) - vars.delta_x;
	slope =(start->y - end->y) / (start->x - end->x);
	bsh_algo(&current, start, &vars);

	//case 2 (slope < 0)
	current.x = start->x;
	current.y = -(start->y);
	vars.delta_x = start->x - end->x;
	vars.delta_y = -(start->y) - (-(end->y));
	slope =(start->y - end->y) / (start->x - end->x);
	bsh_algo(&current, close, &vars);
	
	//case 3 (slope > 1)
	current.x = start->y;
	current.y = start->x;
	vars.delta_x = end->y - start->y;
	vars.delta_y = end->x - start->x;
	vars.next_decis_para = (2 * vars.delta_y) - vars.delta_x;
	slope =(end->x - start->x) / (end->y - start->y);
	bsh_algo(&current, close, &vars);


}

void bsh_algo_nor(t_vertex *current, t_vertex *end, t_bsh_vars *vars)
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
}

void bsh_algo_c2(t_vertex *current, t_vertex *end, t_bsh_vars *vars)
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
}

void bsh_algo_c3(t_vertex *current, t_vertex *end, t_bsh_vars *vars)
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

void bsh(t_vertex *start, t_vertex *end)
{
	t_bsh_vars	vars;
	t_vertex	current;
	float		slope;
	int			scenerio;

	current.x = start->x;
	current.y = start->y;
	vars.delta_x = end->x - start->x;
	vars.delta_y = end->y - start->y;
	vars.next_decis_para = (2 * vars.delta_y) - vars.delta_x;
	slope =(end->y - start->y) / (end->x - start->x);
	bsh_algo(&current, end, &vars);
}

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