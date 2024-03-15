/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_mgt_val_wcol.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 19:24:21 by chuleung          #+#    #+#             */
/*   Updated: 2024/03/15 19:30:28 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	**modify_strs_w_col_val(char **str_before_atoi, int len)
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
		strs_aft_modi[i] = create_str_w_col_val(str_before_atoi[i]);
		i++;
	}
	free_all(str_before_atoi);
	return(strs_aft_modi);
}

int	*create_values_str_w_col(char *all_lines)
{
	char	**strs_before_atoi;
	int		*values_str;
	int		len;

	len = 0;
	strs_before_atoi = ft_split(all_lines, ' ');
	while (strs_before_atoi[len])
		len++;
	modify_strs_w_col_val(strs_before_atoi, len);
	values_str = NULL;
	creation_process(&values_str, strs_before_atoi, len);
	free_all(strs_before_atoi);
	return(values_str);
}