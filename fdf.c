/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 06:51:57 by obouizga          #+#    #+#             */
/*   Updated: 2022/05/21 17:14:53 by obouizga         ###   ########.fr       */
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

*/

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
