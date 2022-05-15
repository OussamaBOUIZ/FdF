/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 06:51:57 by obouizga          #+#    #+#             */
/*   Updated: 2022/05/15 18:33:07 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
	Implementation:
	1- Creating a Window
	2- read a given map
	3-handling Events
	4-learn about Bresenham Algo
	5-learn about isometric projection
	
*/

int	deal_key(int key, void *param)
{
	(void)param;
	printf("Hello from key hook\n");
	ft_putnbr(key);
	ft_putchar('\n');
	if (key == 53)
		exit(1);
	return (0);
}


int	main(int ac, char **av)
{
	void	*mlx_id;
	void	*win_id;
	char	**map;
	t_iso	a;
	t_iso	b;
	
	(void)ac;
	(void)map;
	// manage_error(ac, av);
	// map = read_map(av[1]);
	// if (check_map(map))
	// 	exit(EXIT_FAILURE);
	a.x = ft_atoi(av[2]);
	a.y = ft_atoi(av[3]);
	b.x = ft_atoi(av[4]);
	b.y = ft_atoi(av[5]);
	mlx_id = mlx_init();
	win_id = mlx_new_window(mlx_id, W_W, W_H, "FDF :)");
	plot_line(a, b, mlx_id, win_id);	
	mlx_mouse_hook(win_id, deal_key, (void *)0);
	mlx_expose_hook(win_id, deal_key, (void *)0);
	mlx_key_hook(win_id, deal_key, (void *)0);
	mlx_loop(mlx_id);
	return (0);
}
