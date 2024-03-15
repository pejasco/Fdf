/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_mgt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 17:53:12 by chuleung          #+#    #+#             */
/*   Updated: 2024/03/15 17:53:24 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

include "fdf.h"

int input_status(char **all_lines)
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

t_int_strs *input_mgt(char **all_lines, int wid)
{
	int		i;
	t_int_strs	*all_strs;

	i = 0;
	if ((input_status(all_lines)))
		all_strs = get_strs(all_lines, With_Color, wid);
	else if (!input_status(all_lines))
		all_strs = get_strs(all_lines, Without_Color, wid);
	return (all_strs);
}