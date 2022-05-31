/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   def_unit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 18:50:33 by obouizga          #+#    #+#             */
/*   Updated: 2022/05/31 15:46:47 by obouizga         ###   ########.fr       */
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

t_u	def_unit(int *dim, char **map, char ***cor)
{
	t_u	units;
	t_d	iso_w;
	t_d	iso_h;
	int	ext_z;

	(void)map;
	ext_z = find_ext_z(dim[0], cor);
	iso_w = fabs((t_d)dim[1] + (t_d)dim[0]);
	iso_h = fabs(((t_d)dim[1] + (t_d)dim[0]) * 3 / 4 + ext_z);
	units.x = W_W * 4 / (5 * iso_w);
	units.y = W_H * 4 / (5 * iso_h);
	return (units);
}
