/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:16:15 by chuleung          #+#    #+#             */
/*   Updated: 2024/03/19 22:35:54 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft.h"
# include "mlx.h"
# include <math.h>
# include <stdio.h>
# include <fcntl.h>
# include <X11/keysym.h>

typedef struct s_coord_set
{
	t_coord	open;
	t_coord	close;
	t_coord	current;
} t_coord_set;

typedef struct s_coord
{
	double	x;
	double	y;
	double	z;
	double	RGB;
	double	x_max;
	double	y_max;
} t_coord;

typedef struct s_brese_vars
{
	double	delta_x;
	double	delta_y;
	double	init_decis_para;
	double	prev_decis_para;
	double	decis_para_in_E;
	double	decis_para_in_NE;
} t_brese_vars;

typedef enum e_pix_decis
{
	E,
	NE,
}   t_pix_decis;


typedef enum e_mode
{
	With_Color,
	Without_Color,
}   t_mode;

typedef struct s_int_strs
{
	int     **rgb_strs;
	int     **values_strs;
	int     wid;
}   t_int_strs;


typedef struct s_mlx_data
{
	void *mlx_ptr;
	void *win_ptr;
} t_mlx_data;

typedef struct s_img
{
	void    *img_ptr;
	char    *img_pixels_ptr;
	int     bit_per_pixel;
	int     endian;
	int     line_len;
}   t_img;

typedef struct	s_var
{
	void	*mlx;
	void	*win;
	t_img	img;
}				t_var;



//input_mgt
void input_mgt(t_int_strs *strs,char **all_lines, int wid);

//input_mgt_val
int	**get_values_strs(char **all_lines, t_mode mode, int width);
void creation_process(int **ptrs_to_values_str, char **strs_before_atoi, int len);

//input_mgt_val_w_col
int	*create_values_str_w_col(char *all_lines);

//input_mgt_rgb
int	**get_RGB_strs(char **all_lines, int width);

//utilic
void free_all(char **strs);
void free_all_int(int **strs);
void free_stru(t_int_strs *struc);

//input_mgt_rgb2
void creation_process_rgb(int **ptrs_to_values_str, 
	char **strs_before_atoi, int len);
int whether_colors(char *char_strs);
void	fill_white_for_zero(char **colors_c_arr);
int find_comma(char *str);

//ft_atoi_base
int	ft_atoi_base(char *str, char *base);

//bresenham
int bresenham(t_coord *open, t_coord *close);






























/*
t_int_strs *input_mgt(char **all_lines, int wid);

int	ft_atoi_base(char *str, char *base);

int whether_colors(char *char_strs);

void    free_all(char **strs);

void    fill_white_for_zero(char **colors_c_arr);

int find_comma(char *str);

void	extract_RGB(char *char_str, char **colors_c_arr);

int	check_str_len_for_height(char *char_str);

int	**get_values_strs(char **all_lines, t_mode mode, int width);

int	*create_values_str_w_col(char *all_lines);

int	**get_RGB_strs(char **all_lines, int width);

void creation_process(int **ptrs_to_values_str, 
	char **strs_before_atoi, int len);
*/

#endif
