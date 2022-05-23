/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 15:19:22 by obouizga          #+#    #+#             */
/*   Updated: 2022/05/23 19:33:49 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


int main(int ac, char **av)
{
	char	**map;
	int		*dim;
	int		max_z;

	map = check_get_map(ac, av);
	dim = map_dim(map);
	max_z = find_max_z(map, dim[0]);
	printf("max z value is : %i\n", max_z);
	return (0);		
}