/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:58:42 by chuleung          #+#    #+#             */
/*   Updated: 2024/03/12 14:55:10 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	count_item(char *arry)
{
	int i;

	i = 0;
	while (arry[i])
		i++;
	return (i);
}

int ft_len(int fd, int width)
{
	char    *line;
	char    **char_strs;
	int		**int_strs;
	int     i;
	int     j;
	int		no_of_char_strs;

	i = 0;
	j = 0;

	int_strs = (int **)malloc(sizeof(int *) * (width + 1));
	int_strs[width] = NULL;
	while ((line = get_next_line(fd)) != NULL)
	{
		char_strs = ft_split(line, " ");
		no_of_char_strs = count_item(char_strs);
		while(i < no_of_char_strs)
		{
			


		}

	}


}