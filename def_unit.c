/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   def_unit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 18:50:33 by obouizga          #+#    #+#             */
/*   Updated: 2022/05/24 19:09:58 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_d	def_unit(int *dim, char **map)
{
	t_d	unit;
	t_d	x;
	t_d	y;
	int	max_z;

	max_z = find_max_z(map, dim[0]);
	x = (t_d)dim[1];
	y = fabs(((t_d)dim[1] + (t_d)dim[0]) / 2 - max_z);
	unit = 40;
	return (unit);
}
