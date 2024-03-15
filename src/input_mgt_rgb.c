/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_mgt_rgb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 19:15:54 by chuleung          #+#    #+#             */
/*   Updated: 2024/03/15 19:30:30 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*create_str_w_col_rgb(char *str_before_atoi)
{
	int		j;
	int		len;
	char	*str_aft_modi;

	j = 0;
	if (!whether_colors(str_before_atoi))
		fill_white_for_zero(&str_aft_modi);
	else if (whether_colors(str_before_atoi))
		extract_RGB(str_before_atoi, &str_aft_modi);
	return (str_aft_modi);
}

char	**modify_strs_w_col_rgb(char **str_before_atoi, int len)
{
	int		i;
	int		j;
	char	**strs_aft_modi;

	i = 0;
	j = 0;
	strs_aft_modi = (char **)malloc(sizeof(char *) * (len + 1));
	if (strs_aft_modi == NULL)
		return NULL;
	strs_aft_modi[len] = NULL;
	while(str_before_atoi[i])
	{
		strs_aft_modi[i] = create_str_w_col_rgb(str_before_atoi[i]);
		i++;
	}
	//free_all(str_before_atoi);
	return(strs_aft_modi);
}

int	*create_color_strs_w_col(char *all_lines)
{
	char	**strs_before_atoi;
	int		*values_str;
	int		len;

	len = 0;
	strs_before_atoi = ft_split(all_lines, ' ');
	while (strs_before_atoi[len])
		len++;
	modify_strs_w_col_rgb(strs_before_atoi, len);
	values_str = NULL;
	creation_process(&values_str, strs_before_atoi, len);
	//free_all(strs_before_atoi);
	return(values_str);
}

char	*create_str_w_col_val(char *str_before_atoi)
{
	int		j;
	int		len;
	char	*str_aft_modi;

	j = 0;
	len = check_str_len_for_height(str_before_atoi[j]);
	str_aft_modi = (char *)malloc(sizeof(char) * (len + 1));
	if (str_aft_modi == NULL)
		return NULL;
	str_aft_modi[len] = '\0';
	while (j < len)
	{
		str_aft_modi[j] = str_before_atoi[j];
		j++;
	}
	return (str_aft_modi);
}

int	**get_RGB_strs(char **all_lines, t_mode mode, int width)
{
	int		**strs;
	int		i;

	i = 0;
	strs = (int **)malloc(sizeof(int *) * (width + 1));
	strs[width] = '\0';
	if (mode == Without_Color)
	{
		while (all_lines[i]);	
		{
			strs[i] = create_values_str_no_col(all_lines[i]);
			i++;
		}
	}
	else if (mode == With_Color)
	{
		while (all_lines[i]);	
		{
			strs[i] = create_values_str_no_col(all_lines[i]);
			i++;
		}
	}
	return (strs);
}