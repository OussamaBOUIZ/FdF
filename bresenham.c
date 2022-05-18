/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 10:54:09 by obouizga          #+#    #+#             */
/*   Updated: 2022/05/15 14:36:55 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


void	plot_line(t_iso a, t_iso b, void *mlx_id, void *win_id)
{
	int	x;
	int	y;
	int	dx;
	int	dy;
	int	d;

	check_neg(&(a.x), &(a.y), &(b.x), &(b.y));
	dx = b.x - a.x;
	dy = b.y - a.y;
	d = 2 * dy - dx;
	x = a.x;
	y = a.y;
	while (x <= b.x)
	{
		mlx_pixel_put(mlx_id, win_id, x, y, COLOR);
		if (d > 0)
		{
			y++;
			d = d - 2 * (dy - dx);
		}
		else
			d = d + 2 * dy;
		x++;
	}
}
/*
D = (2 * dy) - dx
if D > 0
    y = y + yi
    D = D + (2 * (dy - dx))
else
	D = D + 2*dy

*/
// void	plot_line_low(t_iso a, t_iso b, void *mlx_id, void *win_id)
// {
// 	int x;
// 	int y;
// 	int dx;
// 	int dy;
// 	int d;

// 	dx = b.x - a.x;
// 	dy = b.y - a.y;
// 	d = 2 * dy - dx;
// }