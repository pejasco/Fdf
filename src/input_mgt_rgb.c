/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_mgt_rgb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 19:15:54 by chuleung          #+#    #+#             */
/*   Updated: 2024/03/16 22:54:34 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	extract_RGB(char *str_before_atoi ,char **colors_c_arr)
{
	int		i;
	int		j;
	int		k;
	int		len;

	i = 0;
	j = i + 1;
	k = 0;
	len = 8;
	*colors_c_arr = (char *)malloc(sizeof(char) * (len + 1));
	if (*colors_c_arr == NULL)
		return ;
	while (str_before_atoi[i] != '0' && str_before_atoi[j] != 'x')
		i++;
	while (str_before_atoi[i])
		*colors_c_arr[k++] = str_before_atoi[i++];
	*colors_c_arr[k] = '\0';
}

char	*create_str_w_col_rgb(char *str_before_atoi)
{
	int		j;
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
	char	**strs_aft_modi;

	i = 0;
	strs_aft_modi = (char **)malloc(sizeof(char *) * (len + 1));
	if (strs_aft_modi == NULL)
		return NULL;
	strs_aft_modi[len] = NULL;
	while(str_before_atoi[i])
	{
		strs_aft_modi[i] = create_str_w_col_rgb(str_before_atoi[i]);
		i++;
	}
	return(strs_aft_modi);
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
	while (strs_before_atoi[len])
		len++;
	strs_aft_modi = modify_strs_w_col_rgb(strs_before_atoi, len);
	values_str = NULL;
	free_all(strs_before_atoi);
	creation_process(&values_str, strs_aft_modi, len);
	free_all(strs_before_atoi);
	return(values_str);
}


int	**get_RGB_strs(char **all_lines, int width)
{
	int		**strs;
	int		i;

	i = 0;
	strs = (int **)malloc(sizeof(int *) * (width + 1));
	strs[width] = '\0';
	while (all_lines[i]);	
	{
			strs[i] = create_color_str_w_col(all_lines[i]);
			i++;
	}
	return (strs);
}