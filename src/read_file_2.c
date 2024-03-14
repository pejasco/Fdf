/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:58:42 by chuleung          #+#    #+#             */
/*   Updated: 2024/03/14 13:17:50 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		count_item(char *arry)
{
	int i;

	i = 0;
	while (arry[i])
		i++;
	return (i);
}

int		whether_colors(char *char_strs)
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
	if (*colors_c_arr == 0)
		return ;
	ft_strlcpy(*colors_c_arr, "0x000000", len + 1);
}

void	extract_RGB(char *char_str, char **colors_c_arr)
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
	if (*colors_c_arr == 0)
		return ;
	while (char_str[i] != '0' && char_str[j] != 'x')
		i++;
	while (char_str[i])
	{
		*colors_c_arr[k] = char_str[i];
		k++;
		i++;
	}
	*colors_c_arr[k] = '\0';
}

int	check_str_len_for_height(char *char_str)
{
	int		i;

	i = 0;
	while (char_str[i] && char_str[i] != ',') 	
		i++;
	return (i);
}

void	extract_RGB(char *char_str, char **colors_c_arr)
{
	int		i;
	int		len;

	i = 0;
	len = check_str_len_for_height(char_str);
	*colors_c_arr = (char *)malloc(sizeof(char) * (len + 1));
	while (i < len)
	{
		*colors_c_arr[i] = char_str[i];
		i++;
	}
	*colors_c_arr[i] = '\0';
}

void	extract_colors(char *char_str, char *colors_c_arr, int whether_color)
{
	int 	len;
	int		i;

	i = 0;
	len = 9;
	if (!whether_color)
		colors_c_arr = (char *)malloc(sizeof(char) * (len + 1));
	else if (whether_color)
	{
		len = ft_strlen(&(char_str));
		colors_c_arr = (char *)malloc(sizeof(char) * (len + 1));
	}
	if (!whether_color)


	while(char_str[i])
	{
		colors_c_arr = char_str[i]

		i++;
	}



}


char	**create_colors_c_arrs(char **char_strs, int nbr_of_items)
{
	char	**colors_c_arrs;
	int		i;
	int		j;
	int		k;
	int		len;
	
	i = 0;
	j = 0;
	k = 0;
	colors_c_arrs = (char **)malloc(sizeof(char *) * (nbr_of_items +1));
	while(char_strs[i])
	{
		j = 0;
		while(char_strs[i][j])
		{
			if (whether_colors == 1)
			{
				extract_color_data(				



			}			

			else if (whether_colors == 0)
			{
				



			}
			k = 0;
			if((char_strs[i][j] == '0') && (char_strs[i][j + 1] == 'x'))
			{
				len = ft_strlen(&(char_strs[i][j]));
				colors_c_arrs[i] = (char *)malloc(sizeof(char) * (len + 1));

				k++;	
			}


			j++;
		}
		i++;
	}

	return(colors_c_arrs);
}

char **create_val_c_arrs(char **char_strs, int nbr_of_items)
{
	char	**data_c_arrs;




	return(data_c_arrs);
}











int **create_int_str(int fd, int width)
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
