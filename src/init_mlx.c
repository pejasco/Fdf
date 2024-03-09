/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 01:41:42 by chuleung          #+#    #+#             */
/*   Updated: 2024/03/09 18:07:27 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
int deal_key(int key, void *param)
{
    ft_printf("%c\n", key);
    mlx_pixel_put(((t_lm *) param)->mlx_ptr, ((t_lm *) param)->win_ptr, 250, 250, 0xABCABC);
    return (0);
}
*/
int handle_input(int key, t_mlx_data *data)
{
    if (key == XK_Escape)
    {
        ft_printf("%d key (ESC) has been pressed(%c)\n\n", key, key);
        mlx_destroy_window(data->mlx_ptr, data->win_ptr);
        mlx_destroy_display(data->mlx_ptr);
        free(data->mlx_ptr);
        exit (1);
    }
    ft_printf("%d key has been pressed(%c)\n\n", key, key);
    return (0);
}

int main()
{
    t_mlx_data data;

    data.mlx_ptr = mlx_init();
    data.win_ptr = mlx_new_window(data.mlx_ptr, 500, 500, "diu");
    mlx_pixel_put(data.mlx_ptr, data.win_ptr, 250, 250, 0xABCABC);
    mlx_key_hook(data.win_ptr, handle_input, &data);
    //mlx_key_hook(config.win_ptr, deal_key, &config);
    mlx_loop(data.mlx_ptr);
}




