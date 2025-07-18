/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_mgt_rgb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 19:22:29 by chuleung          #+#    #+#             */
/*   Updated: 2024/04/05 16:32:29 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	creation_process_rgb(int **ptrs_to_values_str,
	char **strs_aft_modi, int len)
{
	int		j;
	int		k;
	int		temp;

	j = 0;
	k = 0;
	(*ptrs_to_values_str) = (int *)malloc(sizeof(int) * (len + 1));
	(*ptrs_to_values_str)[k++] = len;
	while (strs_aft_modi[j])
	{
		temp = ft_atoi_base(strs_aft_modi[j++], "0123456789abcdef");
		(*ptrs_to_values_str)[k++] = temp;
	}
}

int	whether_colors(char *char_strs)
{
	int		i;

	i = 0;
	while (char_strs[i])
	{
		if (char_strs[i] == '0' && char_strs[i + 1] == 'x')
			return (1);
		i++;
	}
	return (0);
}

int	find_comma(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ',')
			return (1);
		i++;
	}
	return (0);
}
