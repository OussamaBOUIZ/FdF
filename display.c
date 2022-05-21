/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 16:30:20 by obouizga          #+#    #+#             */
/*   Updated: 2022/05/21 16:54:04 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	display(void **mlx, int *dim, char **map)
{
	char	***cord;
	t_iso	**iso;

	cord = get_cords(map, dim[0]);
	iso = cords_atoi(cord, dim);
	drawing(iso, dim, mlx);
}
