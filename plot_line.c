/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plot_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 16:29:42 by obouizga          #+#    #+#             */
/*   Updated: 2022/09/29 16:26:51 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_pixel(t_data *data, int x, int y, int color)
{
	if (x < W_W && y < W_H)
		my_mlx_pixel_put(data, x, y, color);
}

int	*line_change(t_iso a, t_iso b)
{
	int	*big_d;

	big_d = malloc(sizeof(int) * 2);
	if (!big_d)
		exit(EXIT_FAILURE);
	big_d[0] = b.x - a.x;
	big_d[1] = b.y - a.y;
	return (big_d);
}

void	plot_line_low(t_iso a, t_iso b, t_data *img, t_off offset)
{
	int	*dv;
	int	yi;
	int	d;

	dv = line_change(a, b);
	yi = 1;
	if (dv[1] < 0)
	{
		yi = -1;
		dv[1] = -dv[1];
	}
	d = 2 * dv[1] - dv[0];
	while (a.x < b.x)
	{
		put_pixel(img, a.x + offset.x_off, a.y + offset.y_off, a.clr);
		if (d > 0)
		{
			a.y += yi;
			d = d + 2 * (dv[1] - dv[0]);
		}
		else
			d = d + 2 * dv[1];
		a.x++;
	}
	free(dv);
}

void	plot_line_high(t_iso a, t_iso b, t_data *img, t_off offset)
{
	int	*dv;
	int	xi;
	int	d;

	dv = line_change(a, b);
	xi = 1;
	if (dv[0] < 0)
	{
		xi = -1;
		dv[0] = -dv[0];
	}
	d = 2 * dv[0] - dv[1];
	while (a.y < b.y)
	{
		put_pixel(img, a.x + offset.x_off, a.y + offset.y_off, a.clr);
		if (d > 0)
		{
			a.x += xi;
			d = d + 2 * (dv[0] - dv[1]);
		}
		else
			d = d + 2 * dv[0];
		a.y++;
	}
	free(dv);
}

void	plot_line(t_iso a, t_iso b, t_data *img, t_off offset)
{
	if (fabs(b.y - a.y) < fabs(b.x - a.x))
	{
		if (a.x > b.x)
			plot_line_low(b, a, img, offset);
		else
			plot_line_low(a, b, img, offset);
	}
	else
	{
		if (a.y > b.y)
			plot_line_high(b, a, img, offset);
		else
			plot_line_high(a, b, img, offset);
	}
}
