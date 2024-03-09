#! /usr/bin/bash

cc -g -I ../inc/ -I ../lib/libft/inc/ -I ../lib/minilibx-linux -L ../lib/libft/lib -L ../lib/minilibx-linux init_mlx.c -lft -lmlx -pg -Wall -Wextra -Werror -lX11 -lXext
./a.out