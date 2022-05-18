/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 06:51:57 by obouizga          #+#    #+#             */
/*   Updated: 2022/05/18 18:02:57 by obouizga         ###   ########.fr       */
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



// int	main(int ac, char **av)
// {
// 	char	**map;
// 	char	***cords;
// 	t_iso	**iso;
// 	int		row;
// 	int		col;

// 	(void)ac;
// 	map = read_map(av[1]);
// 	// printf("the length of this map's : %i\n", ptr_str_len(map));
// 	row = ptr_str_len(map);
// 	cords = get_cords(map, row);
// 	col = ptr_str_len(cords[0]);
// 	printf("row : %i \n", row);
// 	printf("col : %i \n", col);
// 	iso = cords_atoi(cords, ptr_str_len(map), col);
// 	// print_iso_table(iso, col);
// 	// print_tri(cords);
// 	return (0);
// }


*/

int	main(int ac, char **av)
{
	void	*mlx_id;
	void	*win_id;
	char	**map;
	int		*row_col;
	char	***cords;
	t_iso	**iso;

	row_col = malloc(sizeof(int) * 2);
	if (!row_col)
		return (1);
	manage_error(ac, av);
	map = read_map(av[1]);
	if (check_map(map))
		exit(EXIT_FAILURE);
	mlx_id = mlx_init();
	row_col[0] = ptr_str_len(map);
	cords = get_cords(map, row_col[0]);
	row_col[1] = ptr_str_len(cords[0]);
	iso = cords_atoi(cords, row_col[0], row_col[1]);
	win_id = mlx_new_window(mlx_id, W_W * row_col[0], W_H * row_col[1], "FDF");
	print_iso_table(iso, row_col[1]);
	display_map(iso, row_col, mlx_id, win_id);
	mlx_loop(mlx_id);
	return (0);
}
