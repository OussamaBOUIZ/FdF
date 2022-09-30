/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 06:51:57 by obouizga          #+#    #+#             */
/*   Updated: 2022/09/30 17:30:27 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
	Implementation:
	1- Creating a Window
	2- read a given map
	3-learn about Bresenham Algo
	4-handling Events
	5-learn about isometric projection
	
	MAIN:
		HANDLING ERROR and GET MAP:
			check arguments.
			read map.
			check map.
			return (map)
		INQUIRE MAP:
			return (col_n & row_n).
		DISPLAY:
			get cordinates.
			convert cordinates from cartesian to isometric
			while drawing the line we should multiply x and y by a unit so that 
			we get dynamic display. In addition, ...
			Thinking=> defining the origin of the plane and the units simultaneously
		HANDLING EVENTS:
			handle ESC
			handle Red Cross


			H : 1920
			W : 1080


	ABOUT THE MLX:
		- mlx_init() establishes a connection to the correct graphical system and 
		will return a void* which
		holds the location of our current MLX instance.
		- mlx_new_window() will return a pointer to the window we just created.
		- mlx_loop() will initiate the window rendering.

*/

int	main(int ac, char **av)
{
	t_data	img;
	int		*dim;
	t_mlx	mlx;
	char	**map;

	map = check_get_map(ac, av);
	mlx.m_id = mlx_init();
	if (!mlx.m_id)
		mlx_id_error();
	mlx.w_id = mlx_new_window(mlx.m_id, W_W, W_H, "FDF");
	if (!mlx.w_id)
		win_id_error(mlx.w_id);
	img.img = mlx_new_image(mlx.m_id, W_W, W_H);
	if (!img.img)
		image_error(img.img);
	img.ad = mlx_get_data_addr(img.img, &img.bpp, &img.l_l, &img.endian);
	if (!img.ad)
		get_data_addr_error(img.ad);
	dim = map_dim(map);
	display(&img, dim, map);
	mlx_put_image_to_window(mlx.m_id, mlx.w_id, img.img, 0, 0);
	mlx_key_hook(mlx.w_id, deal_key, (void *)0);
	mlx_hook(mlx.w_id, 17, 0, close_window, NULL);
	mlx_loop(mlx.m_id);
	return (0);
}
