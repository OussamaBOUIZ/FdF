/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 12:39:29 by obouizga          #+#    #+#             */
/*   Updated: 2022/05/15 18:49:06 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	plot_low(t_iso a, t_iso b, void *m_id, void *w_id)
{
	double	dy;
	double	dx;
	double	d;

	dy = b.y - a.y;
	dx = b.x - a.x;
	d = 2 * dy - dx;
	while (a.x < b.x)
	{
		mlx_pixel_put(m_id, w_id, a.x, a.y, COLOR);
		if (d > 0)
		{
			a.y++;
			d = d - 2 * dx;
		}
		d = d + 2 * dy; 
		a.x++;
	}
}

void	plot_too_low(t_iso a, t_iso b, void *m_id, void *w_id)
{
	double	dy;
	double	dx;
	double	d;

	dy = b.y - a.y;
	dx = b.x - a.x;
	d = 2 * dy - dx;
	while (a.y < b.y)
	{
		mlx_pixel_put(m_id, w_id, a.x, a.y, COLOR);
		if (d > 0)
		{
			a.x++;
			d = d - 2 * dx;
		}
		d = d + 2 * dy; 
		a.y++;
	}
}

void	plot_high(t_iso a, t_iso b, void *m_id, void *w_id)
{
	double	dy;
	double	dx;
	double	d;

	dy = b.y - a.y;
	dx = b.x - a.x;
	d = 2 * dy - dx;
	while (a.x < b.x)
	{
		mlx_pixel_put(m_id, w_id, a.x, a.y, COLOR);
		if (d > 0)
		{
			b.y--;
			d = d - 2 * dx;
		}
		d = d + 2 * dy; 
		a.x++;
	}
}

void	plot_too_high(t_iso a, t_iso b, void *m_id, void *w_id)
{
	double	dy;
	double	dx;
	double	d;

	dy = b.y - a.y;
	dx = b.x - a.x;
	d = 2 * dy - dx;
	while (a.x < b.x)
	{
		mlx_pixel_put(m_id, w_id, a.x, b.y, COLOR);
		if (d > 0)
		{
			a.x++;
			d = d - 2 * dx;
		}
		d = d + 2 * dy; 
		b.y--;
	}
}

void	draw_line(t_iso a, t_iso b, void *m_id, void *w_id)
{
	double	m;

	check_neg(&(a.x), &(a.y), &(b.x), &(b.y));
	m = slope(a, b);
	if (m > 0 && m < 1)
		plot_low(a, b, m_id, w_id);
	else if (m > 1)
		plot_too_low(a, b, m_id, w_id);
	else if (m < 0 && m > -1)
		plot_high(a, b, m_id, w_id);
	else if (m < -1)
		plot_too_high(a, b, m_id, w_id);
}


// 0 < m < 1 x changes more than y ( x inc & y inc) Low Line
// m > 1 y changes more than x (x inc & y inc) Too Low Line
// -1 < m < 0 x changes more than y ( x inc & y dec) High Line
// m < -1 y changes more than x ( x inc & y dec) Too High Line


// plot LOW  line   D = (2 * dy) - dx
// plot HIGH line   D = (2 * dx) - dy
