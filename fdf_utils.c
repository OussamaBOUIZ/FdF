/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 11:56:48 by obouizga          #+#    #+#             */
/*   Updated: 2022/05/30 14:56:46 by obouizga         ###   ########.fr       */
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

t_iso	to_isom(double x, double y, t_atoi zee, t_u units)
{
	t_iso	iso;

	iso.x = (x - y);
	iso.y = ((x + y) * 3 / 4 - zee.val);
	iso.x = iso.x * units.x;
	iso.y = iso.y * units.y;
	iso.clr = zee.clr;
	return (iso);
}

/*
t_iso	to_isom(double x, double y, double z, t_u units)
{
	t_iso	iso;

	iso.x = (x - y);
	iso.y = ((x + y) * 3 / 4 - z);
	iso.x = iso.x * units.x;
	iso.y = iso.y * units.y;
	return (iso);
}
*/
