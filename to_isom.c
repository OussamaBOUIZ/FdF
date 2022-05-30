/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 11:56:48 by obouizga          #+#    #+#             */
/*   Updated: 2022/05/30 19:34:43 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
