/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_dim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 15:33:17 by obouizga          #+#    #+#             */
/*   Updated: 2022/05/22 10:17:06 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	*map_dim(char **map)
{
	char	**line;
	int		*dim;
	int		c;
	int		r;

	r = 0;
	c = 0;
	dim = malloc(sizeof(int) * 2);
	line = ft_split(map[0], ' ');
	while (map[r])
		r++;
	while (line[c])
		c++;
	dim[0] = r;
	dim[1] = c;
	printf("Map size: H -> %i, W -> %i\n", dim[0], dim[1]);
	return (dim);
}
