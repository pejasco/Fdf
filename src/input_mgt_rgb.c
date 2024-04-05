/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_mgt_rgb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 19:15:54 by chuleung          #+#    #+#             */
/*   Updated: 2024/04/05 16:50:14 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*create_str_w_col_rgb(char *str_before_atoi)
{
	char	*str_aft_modi;

	str_aft_modi = NULL;
	if (!whether_colors(str_before_atoi))
		str_aft_modi = "ffffff";
	else if (whether_colors(str_before_atoi))
		str_aft_modi
			= ft_strchr(str_before_atoi, ',') + 3;
	return (str_aft_modi);
}

char	**modify_strs_w_col_rgb(char **str_before_atoi, int len)
{
	int		i;
	char	**strs_aft_modi;

	i = 0;
	strs_aft_modi = (char **)malloc(sizeof(char *) * (len + 1));
	if (strs_aft_modi == NULL)
		return (NULL);
	strs_aft_modi[len] = NULL;
	while (str_before_atoi[i] && ft_isalnum(str_before_atoi[i][0]))
	{
		strs_aft_modi[i] = create_str_w_col_rgb(str_before_atoi[i]);
		i++;
	}
	return (strs_aft_modi);
}

int	*create_color_strs_w_col(char *all_lines)
{
	char	**strs_before_atoi;
	char	**strs_aft_modi;
	int		*values_str;
	int		len;

	len = 0;
	strs_aft_modi = NULL;
	strs_before_atoi = ft_split(all_lines, ' ');
	while (strs_before_atoi[len] && ft_isdigit(strs_before_atoi[len][0]))
		len++;
	strs_aft_modi = modify_strs_w_col_rgb(strs_before_atoi, len);
	values_str = NULL;
	creation_process_rgb(&values_str, strs_aft_modi, len);
	free_all(strs_before_atoi);
	free(strs_aft_modi);
	return (values_str);
}

int	**get_rgb_strs(char **all_lines, int width)
{
	int		**strs;
	int		i;

	i = 0;
	strs = (int **)malloc(sizeof(int *) * (width + 1));
	strs[width] = NULL;
	while (all_lines[i])
	{
		strs[i] = create_color_strs_w_col(all_lines[i]);
		i++;
	}
	return (strs);
}
