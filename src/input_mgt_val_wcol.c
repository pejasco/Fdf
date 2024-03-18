/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_mgt_val_wcol.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 19:24:21 by chuleung          #+#    #+#             */
/*   Updated: 2024/03/18 23:14:50 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	check_str_len_for_height(char *char_str)
{
	int		i;

	i = 0;
	while (char_str[i] && char_str[i] != ',') 	
		i++;
	return (i);
}

char	*create_str_w_col_val(char *str_before_atoi)
{
	int		j;
	int		len;
	char	*str_aft_modi;

	j = 0;
	len = check_str_len_for_height(str_before_atoi);
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

/*
char	**modify_strs_w_col_val(char **str_before_atoi, int len)
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
		strs_aft_modi[i] = create_str_w_col_val(str_before_atoi[i]);
		i++;
	}
	return(strs_aft_modi);
}
*/
int	*create_values_str_w_col(char *all_lines)
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
	//while (strs_before_atoi[len])
	//	len++;
	//modify_strs_w_col_val(strs_before_atoi, len);
	values_str = NULL;
	ft_printf("w_col: %d\n", len);
	creation_process(&values_str, strs_before_atoi, len);
	free_all(strs_before_atoi);
	return(values_str);
}