/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_max_z.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 18:31:03 by obouizga          #+#    #+#             */
/*   Updated: 2022/05/23 19:35:23 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	find_max_z(char **map, int row)
{
	char	***cords;
	int		i;
	int		j;
	int		max;

	cords = get_cords(map, row);
	max = 0;
	i = 0;
	while (i < row)
	{
		j = 0;
		while (cords[i][j])
		{
			if (abs(ft_atoi(cords[i][j])) >= max)
				max = abs(ft_atoi(cords[i][j]));
			j++;
		}
		i++;
	}
	return (max);
}
