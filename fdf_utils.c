/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 11:56:48 by obouizga          #+#    #+#             */
/*   Updated: 2022/05/15 14:40:20 by obouizga         ###   ########.fr       */
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

void	check_neg(double *x0, double *y0, double *x1, double *y1)
{
	if (*x0 > *x1 && *y0 > *y1)
	{
		swap(x0, x1);
		swap(y0, y1);
	}
}

t_iso	to_isometric(t_cart cart)
{
	t_iso	iso;

	iso.x = cart.x - cart.y;
	iso.y = ((cart.x + cart.y) / 2) - cart.z;
	return (iso);
}

int	*get_map_dim(char **map)
{
	int	h;
	int	w;
	int	dim[2];

	check_map(map);
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
