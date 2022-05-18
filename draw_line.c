/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 12:39:29 by obouizga          #+#    #+#             */
/*   Updated: 2022/05/18 15:49:06 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
// 0 < m < 1 x changes more than y ( x inc & y inc) Low Line
// m > 1 y changes more than x (x inc & y inc) Too Low Line
// -1 < m < 0 x changes more than y ( x inc & y dec) High Line
// m < -1 y changes more than x ( x inc & y dec) Too High Line
// plot LOW  line   D = (2 * dy) - dx
// plot HIGH line   D = (2 * dx) - dy

/*
	NEED TO HANDLE LINES THAT ARE PAARALLEL TO X OR Y AXIS
*/

void	put_pixel(void *m, void *w, int x, int y)
{
	mlx_pixel_put(m, w, x + W_W / 2, y + W_H / 2, COLOR);
}

void	draw_low_line(t_iso a, t_iso b, void *m_id, void *w_id)
{
	int	dx;
	int	dy;
	int d;
	int	yi;

	dx = b.x - a.x;
	dy = b.y - a.y;
	d = 2 * dy - dx;
	yi = 1;
	if (dy < 0)
	{
		yi = -1;
		dy = -dy;
	}
	while (a.x <= b.x)
	{
		put_pixel(m_id, w_id, a.x, a.y);
		if (d > 0)
		{
			a.y += yi;
			d = d + 2 * (dy - dx);
		}
		else
			d = d + 2 * dy;
		a.x++;
	}
}

void	draw_high_line(t_iso a, t_iso b, void *m_id, void *w_id)
{
	int	dx;
	int	dy;
	int	d;
	int	xi;

	dx = b.x - a.x;
	dy = b.y - a.y;
	d = 2 * dy - dx;
	xi = 1;
	if (dx < 0)
	{
		xi = -1;
		dx = -dx;
	}
	while (a.y <= b.y)
	{
		put_pixel(m_id, w_id, a.x, a.y);
		if (d > 0)
		{
			a.x += xi;
			d = d + 2 * (dx - dy);
		}
		else
			d = d + 2 * dx;
		a.y++;
	}
}

void	draw_line(t_iso a, t_iso b, void *m_id, void *w_id)
{
	double	m;

	check_neg(&(a.x), &(a.y), &(b.x), &(b.y));
	m = slope(a, b);
	if (fabs(m) > 1)
		draw_low_line(a, b, m_id, w_id);
	else
		draw_high_line(a, b, m_id, w_id);
}
