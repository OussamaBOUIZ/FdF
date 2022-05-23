/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 06:51:57 by obouizga          #+#    #+#             */
/*   Updated: 2022/05/23 19:41:27 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
	Implementation:
	1- Creating a Window
	2- read a given map
	3-handling Events
	4-learn about Bresenham Algo
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
		HANDLING EVENTS:
			handle ESC
			handle Red Cross


int	main(int ac, char **av)
{
	char	**map;
	int		*dim;
	void	**mlx;

	map = check_get_map(ac, av);
	mlx = malloc(sizeof(void *) * 2);
	if (!mlx)
		return (1);
	mlx[0] = mlx_init();
	mlx[1] = mlx_new_window(mlx[0], W_W, W_H, "FDF");
	dim = map_dim(map);
	display(mlx, dim, map);
	mlx_loop(mlx[0]);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	img;
	int		*dim;
	void	*m_id;
	void	*w_id;
	char	**map;

	map = check_get_map(ac, av);
	m_id = mlx_init();
	w_id = mlx_new_window(m_id, W_W, W_H, "FDF");
	img.img = mlx_new_image(m_id, W_W, W_H);
	img.ad = mlx_get_data_addr(img.img, &img.bpp, &img.l_l, &img.endian);
	dim = map_dim(map);
	display(&img, dim, map);
	mlx_put_image_to_window(m_id, w_id, img.img, 0, 0);
	mlx_loop(m_id);
	return (0);
}
*/
/*
	A Good formula for calculating window dimensions:
	 W_H = 4 / 3 * iso_row_num;
	 W_W = 5 / 3 * iso_column_num;
*/

int main(int ac, char **av)
{
	char	**map;
	int		*dim;
	int		max_z;

	map = check_get_map(ac, av);
	dim = map_dim(map);
	max_z = find_max_z(map, dim[0]);
	printf("max z value is : %i\n", max_z);
	return (0);		
}
