/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 19:29:13 by chuleung          #+#    #+#             */
/*   Updated: 2024/03/14 22:11:20 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	*create_color_strs_w_col(char *all_lines)
{

fdf
wefwef



}

char	**modify_strs_w_col_rgb(char **str_before_atoi, int len)
{
	int		i;
	char	**strs_aft_modi;

	i = 0;
	strs_aft_modi = (char **)malloc(sizeof(char *) * (len + 1));
	strs_aft_modi[len] = NULL;
	while(str_before_atoi[i])
	{
		str_before_atoi[i] = 
		


	}
	free(str_before_atoi);
	return(strs_aft_modi);
}



char	**modify_strs_w_col_val(char **str_before_atoi, int len)
{
	char	**strs_aft_modi;

	strs_aft_modi = (char **)malloc(sizeof(char *) * (len + 1));



	free(str_before_atoi);
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
	
	values_str = NULL;
	creation_process(&values_str, strs_before_atoi, len);
	free_all(strs_before_atoi);
	return(values_str);
}

void creation_process(int **ptrs_to_values_str, 
	char **strs_before_atoi, int len)
{
	int		j;
	int		k;
	int		temp;

	j = 0;
	k = 0;
	*ptrs_to_values_str = (int *)malloc(sizeof(int) * (len + 1));
	*ptrs_to_values_str[k++] = len;
	while(strs_before_atoi[j])
	{
		temp = ft_atoi(strs_before_atoi[j++]);
		*ptrs_to_values_str[k++] = temp;
	}
}

int	*create_values_str_no_col(char *all_lines)
{
	char	**strs_before_atoi;
	int		*values_str;
	int		len;

	len = 0;
	strs_before_atoi = ft_split(all_lines, ' ');
	while (strs_before_atoi[len])
		len++;
	values_str = NULL;
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


t_int_strs	**get_strs(char **all_lines, t_mode mode, int width) 
{
	t_int_strs strs;

	if (mode == Without_Color)
	{
		strs.rgb_strs = NULL;
		strs.values_strs = get_values_strs(all_lines, Without_Color, width);
	}
	else if (mode == With_Color)
	{
		strs.rgb_strs = get_color_strs
		strs.values_strs = get_values_strs(all_lines, mode, width)
	}
	return
}




int find_wid(int fd)
{
	char	*line;
	int		width;

	width = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		width++;
		free(line);
	}
	return (width);
}

int read_file(char *file_name)
{
	int     fd;
	char    *line;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Incorrect file name!");
		return (-1);
	}
	return (fd);
}

char	**extract_line(int fd, int wid) 
{
	char	*line;
	char	**all_the_lines;
	int		i;
	int		len;

	i = 0;
	all_the_lines = (char **)malloc(sizeof(char *) * (wid + 1));
	all_the_lines[wid] = '\0';
	while ((line = get_next_line(fd)) != NULL)
	{
		len = ft_strlen(line);
		all_the_lines[i] = malloc(sizeof(char) * (len + 1));
		ft_strlcpy(all_the_lines[i], line, (len + 1));
		i++;
		free(line);
	}
	close(fd);
	return (all_the_lines);
}


int input_status(char **all_lines)
{
	int		i;

	i = 0;
	while (all_lines[i])
	{
		if (find_comma(all_lines[i]))
			return (1);
		i++;
	}
	return (0);
}

t_int_strs *input_mgt(char **all_lines, int wid)
{
	int		i;
	t_int_strs	*all_strs;

	i = 0;
	if ((input_status(all_lines)))
		all_strs = get_strs(all_lines, With_Color, wid);
	else if (!input_status(all_lines))
		all_strs = get_strs(all_lines, Without_Color, wid);

	
	return (all_strs);
}

int	main(int ac, char **av)
{
	int		fd;
	int		wid;
	char	**all_lines;
	t_int_strs	*strs;


	fd = 0;
	wid = 0;
	all_lines = NULL;
	if (ac != 2 || ((fd = read_file(av[1])) == -1))
		return (1);
	wid = find_wid(fd);
	all_lines = extract_line(fd, wid);
	strs = input_mgt(all_lines, wid);








	return (0);
}

/*
#include <fcntl.h>
#include <stdio.h>

int main(void) {
	int fd = open("file.txt", O_RDONLY);
	char *line;

	if (fd == -1) {
		printf("Failed to open file\n");
		return 1;
	}

	while ((line = get_next_line(fd)) != NULL) {
		printf("%s\n", line);
		free(line);
	}

	close(fd);

	return 0;
}
*/


/*
int read_file(char *file_name)
{
	int     fd;
	char    *line;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Incorrect file name!");
		return (1);
	}
	//line = get_next_line(fd);
	//printf("%s", line);
	//free(line);
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free (line);
	}
	close(fd);
	return (0);
}
*/