/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_mgt_rgb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 19:22:29 by chuleung          #+#    #+#             */
/*   Updated: 2024/03/16 19:25:08 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int whether_colors(char *char_strs)
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

void	fill_white_for_zero(char **colors_c_arr)
{
	int		i;
	int		len;

	i = 0;
	len = 8;
	*colors_c_arr = (char *)malloc(sizeof(char) * (len + 1));
	if (!(whether_colors(*colors_c_arr)))
		return ;
	ft_strlcpy(*colors_c_arr, "0xFFFFFF", len + 1);
}

int find_comma(char *str)
{
  int   i;

  i = 0;
  while (str[i])
  { 
    if (str[i] == ',')
      return (1);
    i++;
  }
  return (0);
}
