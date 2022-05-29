/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 11:56:48 by obouizga          #+#    #+#             */
/*   Updated: 2022/05/28 06:46:10 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	swap(double *a, double *b)
{
	double	c;

	c = *a;
	*a = *b;
	*b = c;
}

double	slope(t_iso a, t_iso b)
{
	return ((b.y - a.y) / (b.x - a.x));
}

t_d	max(t_d a, t_d b)
{
	t_d	max;

	if (a > b)
		max = a;
	else
		max = b;
	return (b);
}

t_iso	to_isom(double x, double y, double z, t_u units)
{
	t_iso	iso;

	iso.x = (x - y);
	iso.y = ((x + y) * 3 / 4 - z);
	iso.x = iso.x * units.x;
	iso.y = iso.y * units.y;
	return (iso);
}

int	*get_map_dim(char **map)
{
	int	h;
	int	w;
	int	*dim;

	check_map(map);
	dim = malloc(sizeof(int) * 2);
	if (!dim)
		return (0);
	h = 0;
	w = 0;
	while (map[h])
		h++;
	if (h)
		while (map[1][w])
			w++;
	dim[0] = w;
	dim[1] = h;
	return (dim);
}
