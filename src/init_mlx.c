/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 01:41:42 by chuleung          #+#    #+#             */
/*   Updated: 2024/03/09 03:06:20 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


int deal_key(int key, void *param)
{
    ft_printf("Key entered: %d", &key);
    mlx_pixel_put(((t_lm *) param)->mlx_ptr, ((t_lm *) param)->win_ptr, 250, 250, 0xFFFFFF);
    return (0);
}

int main()
{
    t_lm config;

    config.mlx_ptr = mlx_init();
    config.win_ptr = mlx_new_window(config.mlx_ptr, 500, 500, "diu");
    mlx_key_hook(config.win_ptr, deal_key, &config);
    mlx_loop(config.mlx_ptr);
}




