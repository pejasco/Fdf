/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:16:15 by chuleung          #+#    #+#             */
/*   Updated: 2024/03/30 16:45:04 by chuleung         ###   ########.fr       */
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

#define WIDTH (1920)
#define HEIGHT (1080)
#define MAX_COL (4)
#define MAX_ROW (4)

//struc for read
typedef	struct s_read_vars
{
	int		fd;
	int		wid;
} 	t_read_vars;

//struc for bresenham


//t_bsh_	bsh_process_coord;
//t_bsh_res	bsh_result_coord;
//t_iso	iso_coord;
//t_scal	scal_coord;
//t_vertex	rota_coord;
//t_vertex	tran_coord;

typedef struct s_px_corrd
{
	int		x;
	int		y;
	int		RGB;
} t_px_corrd;

//stru
typedef	struct 

typedef struct s_vertex
{
	double		x;
	double		y;
	double		z;
	int			RGB;
	int			wid;
	int			len;
	t_mx		real_coord;
} t_vertex;

typedef struct s_matrix
{
	int			row_num;
	int			col_num;
	double		entries[MAX_ROW][MAX_COL];
} t_mx;


typedef struct s_bsh_vars
{
	double		delta_x;
	double		delta_y;
	double		cur_decis_para;
	double		next_decis_para;
	double		slope;
	double		slope_aft_adj;
	int			x1_lar_than_x2;
	int			scenerio;
	int			scen_1_to_scen_2;
	int			scen_2_to_scen_1;
	int			init_check;
	t_vertex	start_temp;
	t_vertex	end_temp;
	t_vertex	current_temp;
	double	start_temp_x_dummy;
	double	start_temp_y_dummy;
	double	end_temp_x_dummy;
	double	end_temp_y_dummy;
	double	cur_temp_x_dummy;
	double	cur_temp_y_dummy;
} t_bsh_vars;

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

typedef struct s_img
{
	void    *img_ptr; //ptr to mlx_new_image
	char    *img_pixels_ptr; //ptr to the pixels of a image
	int     bits_per_pixel; //8 * 4bytes    1 pixel = 4 bits = 32
	int     endian; 
	int     line_len; //Line len is in bytes. WIDTH 800 len_line ~3200 (can differ for alignment)
}   t_img;

typedef struct s_map
{
	t_vertex	*vertexes;
	int			col_num;
	int			row_num;
}	t_map;



typedef struct s_mlx_data
{
	void 	*mlx_ptr; //(before: x_lib)
	void 	*win_ptr; //(before: win)
	t_img	img_vars; //(before: img)
	t_map	map;
} t_mlx_data;

//input_read_file
char	**extract_line(int fd, int wid);
int read_file(char *file_name);
int find_wid(int fd);

//input_mgt
void input_mgt(t_int_strs *strs,char **all_lines, int wid);
int read_file(char *file_name);
int find_wid(int fd);

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
void keep_coord(t_vertex *src, t_vertex *dest);

//input_mgt_rgb2
void creation_process_rgb(int **ptrs_to_values_str, 
	char **strs_before_atoi, int len);
int whether_colors(char *char_strs);
void	fill_white_for_zero(char **colors_c_arr);
int find_comma(char *str);

//ft_atoi_base
int	ft_atoi_base(char *str, char *base);

//bresenham
void bsh(t_vertex *open, t_vertex *close);
void bsh_scen1(t_vertex *start, t_vertex *end, t_vertex *current, t_bsh_vars *vars);
void bsh_scen2(t_vertex *start, t_vertex *end, t_vertex *current, t_bsh_vars *vars);
void bsh_scen3(t_vertex *start, t_vertex *end, t_vertex *current, t_bsh_vars *vars);


//vertex_create
t_vertex	*vertex_create(t_int_strs *all_strs, int wid, t_map *map);

//win_mgt
int		keys_activities(int keysym, t_mlx_data *mlx);
void	draw_dot(t_mlx_data *mlx, t_vertex *all_vertex);
void	supa_pixel_put(t_img *img, int x, int y, int color);
int		f(int keysym, t_mlx_data *data);


//bsh_algo
void draw_current(t_vertex *start, t_vertex *end, t_vertex *current, t_bsh_vars *vars);
void bsh_algo1(t_vertex *start, t_vertex *end, t_vertex *current, t_bsh_vars *vars);
void bsh_algo2(t_vertex *start, t_vertex *end, t_vertex *current, t_bsh_vars *vars);
void bsh_algo3(t_vertex *start, t_vertex *end, t_vertex *current, t_bsh_vars *vars);

//bsh_adj
void	bsh_scen1_adj(t_vertex *start, t_vertex *end, t_vertex *current, t_bsh_vars *vars);
void	bsh_scen2_adj(t_vertex *start, t_vertex *end, t_vertex *current, t_bsh_vars *vars);






























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
