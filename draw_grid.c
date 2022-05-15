/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 18:32:52 by obouizga          #+#    #+#             */
/*   Updated: 2022/05/15 18:33:12 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


void	draw_h_lines(void *m_id, void *w_id, t_point start, t_point end)
{
	int	x;
	int	y;
	int inc;

	inc = W_H * 0.05;
	x = start.x;
	y = start.y;
	while (y <= end.y)
	{
		x = start.x;
		while (++x <= end.x)
			mlx_pixel_put(m_id, w_id, x, y, COLOR);
		y += inc;
	}
}

void	draw_v_lines(void *m_id, void *w_id, t_point start, t_point end)
{
	int	x;
	int	y;
	int	inc;

	inc = W_W * 0.05;
	x = start.x;
	y = start.y;
	while (x <= end.x)
	{
		y = start.y;
		while (++y <= end.y)
			mlx_pixel_put(m_id, w_id, x, y, COLOR);
		x += inc;
	}
}

void	draw_grid(void *m_id, void *w_id)
{
	t_sqr	square;

	square.t_l.x = W_W * S_OFF;
	square.t_l.y = W_H * S_OFF;
	square.t_r.x = W_W * B_OFF;
	square.t_r.y = W_H * S_OFF;
	square.b_l.x = W_W * S_OFF;
	square.b_l.y = W_H * B_OFF;
	square.b_r.x = W_W * B_OFF;
	square.b_r.y = W_H * B_OFF;
	draw_h_lines(m_id, w_id, square.t_l, square.b_r);
	draw_v_lines(m_id, w_id, square.t_l, square.b_r);
}