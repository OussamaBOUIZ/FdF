/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 16:30:20 by obouizga          #+#    #+#             */
/*   Updated: 2022/05/29 11:40:53 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

    // printf("dim[1] : %d\n", dim[1]);
	// printf("DISPLAY ( x: %.0f, y: %.2f)\n", offset.x_off, offset.y_off);
	/*
t_cp	get_offset(int *dim, char **map, char ***cord)
{
	t_cp	offset;
	t_u		units;
	t_d		iso_h;
	int		max_z;

	max_z = find_max_z(map, dim[0], cord);
	iso_h = fabs(((t_d)dim[1] + (t_d)dim[0]) * 3 / 4 - max_z);
	units = def_unit(dim, map, cord);
	offset.x_off = (W_W - dim[1] * units.x) / 2;
	offset.y_off = (W_H - iso_h * units.y) / 2;
	printf("x_off : %.d, y_off : %d\n", offset.x_off, offset.y_off);
	return (offset);
}
	*/

// void	display(t_data *img, int *dim, char **map)
// {
// 	char	***cord;
// 	t_iso	**iso;
// 	t_cp	offset;

// 	offset.x_off = 0;
// 	offset.y_off = 0;
// 	cord = get_cords(map, dim[0]);
// 	iso = cords_atoi(cord, dim, map);
// 	drawing(iso, dim, img, offset);
// 	free_tri_p(cord);
// }



void	display(t_data *img, int *dim, char **map)
{
	char	***cord;
	t_sh	shape;

	cord = get_cords(map, dim[0]);
	shape = cords_atoi(cord, dim, map);
	drawing(shape, dim, img);
	free_tri_p(cord);
}
