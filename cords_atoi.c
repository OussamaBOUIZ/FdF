/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cords_atoi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 07:54:07 by obouizga          #+#    #+#             */
/*   Updated: 2022/05/18 13:13:31 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_iso	**iso_square(int row, int col)
{
	t_iso	**iso;
	int		i;

	iso = malloc(sizeof(t_iso *) * (row + 1));
	if (!iso)
		return (0);
	i = 0;
	while (i < row)
		iso[i++] = malloc(sizeof(t_iso) * col);
	iso[i] = 0;
	return (iso);
}

t_iso	**cords_atoi(char ***cords, int row, int col)
{
	t_iso	**iso;
	int		i;
	int		j;

	printf("---CARTESIAN----\n");
	iso = iso_square(row, col);
	j = 0;
	while (cords[j])
	{
		i = 0;
		while (cords[j][i])
		{
			iso[j][i] = to_isometric((double)i, (double)j, ft_atoi(cords[j][i]));
			printf("( %i, %i, %i) ", i, j, ft_atoi(cords[j][i]));
			i++;
		}
		printf("\n");
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
			printf("(x : %.1f, y : %.1f ) ", iso[j][i].x, iso[j][i].y);
		printf("\n");
		j++;
	}
}
