/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 16:30:20 by obouizga          #+#    #+#             */
/*   Updated: 2022/09/30 16:16:55 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	display(t_data *img, int *dim, char **map)
{
	char	***cord;
	t_sh	shape;

	cord = get_cords(map, dim[0]);
	shape = cords_atoi(cord, dim, map);
	drawing(shape, dim, img);
	free_double_p(map);
	free_tri_p(cord);
}
