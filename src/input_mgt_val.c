/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_mgt_val.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 19:15:50 by chuleung          #+#    #+#             */
/*   Updated: 2024/03/18 23:13:18 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


void creation_process(int **ptrs_to_values_str, 
	char **strs_before_atoi, int len)
{
	int		j;
	int		k;
	int		temp;

	j = 0;
	k = 0;
	(*ptrs_to_values_str) = (int *)malloc(sizeof(int) * (len + 1));
	(*ptrs_to_values_str)[k++] = len;
	while(strs_before_atoi[j])
	{
		temp = ft_atoi(strs_before_atoi[j++]);
		(*ptrs_to_values_str)[k++] = temp;
	}
}

int	*create_values_str_no_col(char *all_lines)
{
	char	**strs_before_atoi;
	int		*values_str;
	int		len;

	len = 0;
	strs_before_atoi = ft_split(all_lines, ' ');
	while (strs_before_atoi[len]
		&& (ft_isdigit(strs_before_atoi[len][0])
		|| strs_before_atoi[len][0] == '-'))
		len++;
	values_str = NULL;
	ft_printf("no col: %d\n", len);
	creation_process(&values_str, strs_before_atoi, len);
	free_all(strs_before_atoi);
	return(values_str);
}

int	**get_values_strs(char **all_lines, t_mode mode, int width)
{
	int		**strs;
	int		i;

	i = 0;
	strs = (int **)malloc(sizeof(int *) * (width + 1));
	strs[width] = '\0';
	if (mode == Without_Color)
	{
		while (all_lines[i])
		{
			strs[i] = create_values_str_no_col(all_lines[i]);
			i++;
		}
	}
	else if (mode == With_Color)
	{
		while (all_lines[i])
		{
			strs[i] = create_values_str_w_col(all_lines[i]);
			i++;
		}
	}
	return (strs);
}