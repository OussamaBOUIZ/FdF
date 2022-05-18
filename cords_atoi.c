/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cords_atoi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 07:54:07 by obouizga          #+#    #+#             */
/*   Updated: 2022/05/18 15:39:57 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_iso	**iso_square(int row, int col)
{
	t_iso	**iso_tab;
	int		i;

	iso_tab = malloc(sizeof(t_iso *) * (row + 1));
	if (!iso_tab)
		return (0);
	i = 0;
	while (i < row)
		iso_tab[i++] = malloc(sizeof(t_iso) * col);
	iso_tab[i] = 0;
	return (iso_tab);
}

t_iso	**cords_atoi(char ***cor, int row, int col)
{
	t_iso	**iso;
	int		i;
	int		j;

	// printf("---CARTESIAN----\n");
	iso = iso_square(row, col);
	j = 0;
	while (cor[j])
	{
		i = 0;
		while (cor[j][i])
		{
			iso[j][i] = to_isometric((t_d)i * 20, (t_d)j * 20, ft_atoi(cor[j][i]) * 20);
			// iso[j][i] = to_isometric((t_d)i, (t_d)j, ft_atoi(cor[j][i]));
			// printf("iso[j][i] : %.0f ", iso[j][i].x);
			// printf("( %i, %i, %i) ", i, j, ft_atoi(cor[j][i]));
			i++;
		}
		// printf("\n");
		j++;
	}
	return (iso);
}

void	print_iso_table(t_iso **iso, int col)
{
	int	j;
	int	i;

	j = 0;
	printf("---ISOMETRIC----\n");
	while (iso[j])
	{
		i = -1;
		while (++i < col)
			printf("( %.1f, %.1f ) ", iso[j][i].x, iso[j][i].y);
		printf("\n");
		j++;
	}
}
