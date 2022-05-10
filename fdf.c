/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 06:51:57 by obouizga          #+#    #+#             */
/*   Updated: 2022/05/10 11:20:00 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
	Discovering:
	1- Create a window
	2- Display something on it (drawing a grid on it)
	
*/

/*
	Implementation:
	1- Creating a Window
	2- read a given map
	
*/

int	deal_key(int key, void *param)
{
	(void)param;
	ft_putnbr(key);
	ft_putchar('\n');
	if (key == 53)
		exit(1);
	return (0);
}

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
		{
			mlx_pixel_put(m_id, w_id, x, y, COLOR);
			printf("%d\n", y);
		}
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

int	main(void)
{
	void	*mlx_id;
	void	*win_id;

	mlx_id = mlx_init();
	win_id = mlx_new_window(mlx_id, W_W, W_H, "FDF :)");
	draw_grid(mlx_id, win_id);
	mlx_key_hook(win_id, deal_key, (void *)0);
	mlx_loop(mlx_id);
	return (0);
}