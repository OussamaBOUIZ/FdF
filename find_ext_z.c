/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_ext_z.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 18:31:03 by obouizga          #+#    #+#             */
/*   Updated: 2022/05/30 19:37:22 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	find_min_z(int row, char ***cor)
{
	int		i;
	int		j;
	int		min;

	i = 0;
	min = 0;
	while (i < row)
	{
		j = 0;
		while (cor[i][j])
		{
			if (ft_atoi(cor[i][j]) < min)
				min = ft_atoi(cor[i][j]);
			j++;
		}
		i++;
	}
	return (min);
}

int	find_max_z(int row, char ***cor)
{
	int		i;
	int		j;
	int		max;

	i = 0;
	max = 0;
	while (i < row)
	{
		j = 0;
		while (cor[i][j])
		{
			if (ft_atoi(cor[i][j]) >= max)
				max = ft_atoi(cor[i][j]);
			j++;
		}
		i++;
	}
	return (max);
}

int	find_ext_z(int row, char ***cor)
{
	int	min;
	int	max;
	int	ext;

	min = abs(find_min_z(row, cor));
	max = abs(find_max_z(row, cor));
	ext = abs(min + max);
	return (ext);
}
