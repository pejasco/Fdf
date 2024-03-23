#include "fdf.h"

int		main()
{

	t_mlx_data	window;

	window.x_lib = mlx_init();
	window.win = mlx_new_window(window.x_lib, 900, 900, "!!!!! FDF !!!!!");
	window.img.img_ptr = mlx_new_image(window.x_lib, SIDE_LEN, SIDE_LEN);
    mlx_key_hook(window.win, to_do_list, &window);
	mlx_loop(window.x_lib);
	printf("main--: %p\n", window.x_lib);
	mlx_destroy_image(window.x_lib, window.img.img_ptr);
	mlx_destroy_window(window.x_lib, window.win);
	mlx_destroy_display(window.x_lib);
	free(window.x_lib);
	return (0);
}