/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_mgt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 16:40:49 by chuleung          #+#    #+#             */
/*   Updated: 2024/04/05 16:48:35 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_strs(t_int_strs **all_strs,
	char **all_lines, t_mode mode, int width)
{
	if (mode == Without_Color)
	{
		(*(all_strs))->rgb_strs = NULL;
		((*all_strs))->values_strs = get_values_strs
			(all_lines, mode, width);
	}
	else if (mode == With_Color)
	{
		(*(all_strs))->rgb_strs
			= get_rgb_strs(all_lines, width);
		(*(all_strs))->values_strs
			= get_values_strs(all_lines, mode, width);
	}
}

int	input_status(char **all_lines)
{
	int		i;

	i = 0;
	while (all_lines[i])
	{
		if (find_comma(all_lines[i]))
			return (1);
		i++;
	}
	return (0);
}

void	input_mgt(t_int_strs *strs, char **all_lines, int wid)
{
	if (input_status(all_lines))
		get_strs(&strs, all_lines, With_Color, wid);
	else
		get_strs(&strs, all_lines, Without_Color, wid);
	free_all(all_lines);
}
