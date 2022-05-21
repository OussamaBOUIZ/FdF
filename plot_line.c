/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plot_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 16:29:42 by obouizga          #+#    #+#             */
/*   Updated: 2022/05/21 11:28:56 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


void	put_pixel(void *m, void *w, int x, int y)
{
	mlx_pixel_put(m, w, x + W_W / 2, y + W_H / 3, 528127); 
}

void	plot_line_low(t_d x0, t_d y0, t_d x1, t_d y1, void *m, void *w)
{
	int	dx;
	int	dy;
	int	yi;
	int	d;

	dx = x1 - x0;
	dy = y1 - y0;
	yi = 1;
	if (dy < 0)
	{
		yi = -1;
		dy = -dy;
	}
	d = 2 * dy - dx;
	while (x0 < x1)
	{
		put_pixel(m, w, x0, y0);
		if (d > 0)
		{
			y0 += yi;
			d = d + 2 * (dy - dx);
		}
		else
			d = d + 2 * dy;
		x0++;
	}
}

void	plot_line_high(t_d x0, t_d y0, t_d x1, t_d y1, void *m, void *w)
{
	int	dx;
	int	dy;
	int	xi;
	int	d;
	
	dx = x1 - x0;
	dy = y1 - y0;
	xi = 1;
	if (dx < 0)
	{
		xi = -1;
		dx = -dx;
	}
	d = 2 * dx - dy;
	while (y0 < y1)
	{
		put_pixel(m, w, x0, y0);
		if (d > 0)
		{
			x0 += xi;
			d = d + 2 * (dx - dy);
		}
		else
			d = d + 2 * dx;
		y0++;
	}
}

void	plot_line(t_d x0, t_d y0, t_d x1, t_d y1, void *m, void *w)
{
	if (fabs(y1 - y0) < fabs(x1 - x0))
	{
		if (x0 > x1)
			plot_line_low(x1, y1, x0, y0, m, w);
		else
			plot_line_low(x0, y0, x1, y1, m, w);
	}
	else
	{
		if (y0 > y1)
			plot_line_high(x1, y1, x0, y0, m, w);
		else
			plot_line_high(x0, y0, x1, y1, m, w);
	}
}
