/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 10:54:09 by obouizga          #+#    #+#             */
/*   Updated: 2022/05/13 10:51:49 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double	get_slope(double x0, double y0, double x1, double y1)
{
	return ((y1 - y0) / (x1 - x0));
}

double	get_const(double m, double x, double y)
{
	return (y - m * x);
}

double	foo(double x, double y, double m, double b)
{
	return (m * x - y + b);
}

void	plot_line(double x0, double y0, double x1, double y1, void *mlx_id, void *win_id)
{
	int	x;
	int	y;
	int	dx;
	int dy;
	int D;

	// m = get_slope(x0, y0, x1, y1);
	// b = get_const(m, x0, y0);
	// printf("The slope's %f\n", m);
	// printf("The const's %f\n", b);
	dx = x1 - x0;
	dy = y1 - y0;
	D = 2 * dy - dx;
	x = x0;
	y = y0;
	while (x <= x1)
	{
		printf("( %i , %i )\n", x, y);
		mlx_pixel_put(mlx_id, win_id, x, y, COLOR);
		if (D > 0)
		{
			y++;
			D = D - 2 * dx;
		}
		D = D + 2 * dy;
		x++;
	}
}


/*
plotLine(x0, y0, x1, y1)
    dx = x1 - x0
    dy = y1 - y0
    D = 2*dy - dx
    y = y0

    for x from x0 to x1
        plot(x,y)
        if D > 0
            y = y + 1
            D = D - 2*dx
        end if
        D = D + 2*dy
*/