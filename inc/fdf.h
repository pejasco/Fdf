/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:16:15 by chuleung          #+#    #+#             */
/*   Updated: 2024/03/14 17:52:05 by chuleung         ###   ########.fr       */
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


typedef struct s_4x4_mtx
{
    float mtx[4][4];
} t_4x4_mtx;

void free_all(char **strs);

#endif
