/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   def_unit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 18:50:33 by obouizga          #+#    #+#             */
/*   Updated: 2022/05/29 06:55:57 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
/*
		units.x = WIN_WIDTH / (2 * ISO_WIDTH);
		units.y = WIN_HEIGHT / (2 * ISO_HEIGHT);



		the center of the display should be positioned right 
		in the center of the window
		so given that the cords of the displayed shape center are (xc,yc)
		and the center of the window is (win_width / 2, win_height / 2)
		we should reach this (xc, yc) == (win_width / 2, win_height / 2)
		
	*/
	// printf("iso_w => %.0f, iso_h => %.0f\n", iso_w, iso_h);

t_u	def_unit(int *dim, char **map, char ***cor)
{
	t_u	units;
	t_d	iso_w;
	t_d	iso_h;
	int	max_z;

	max_z = find_max_z(map, dim[0], cor);
	iso_w = (t_d)dim[1];
	iso_h = fabs(((t_d)dim[1] + (t_d)dim[0]) * 3 / 4 - max_z);
	printf(" ISO_W : %.0f, ISO_H : %.2f\n", iso_w, iso_h);
	units.x = W_W / (2 * iso_w);
	units.y = W_H / (2 * iso_h);
	printf("units.x : %.1f, units.y : %.1f\n", units.x, units.y);
	// free_double_p(map);
	return (units);
}
