/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cords.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 16:29:56 by obouizga          #+#    #+#             */
/*   Updated: 2022/09/29 16:25:11 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	***get_cords(char **map, int row)
{
	char	***cords_s;
	int		i;

	i = 0;
	cords_s = malloc(sizeof(char **) * (row + 1));
	if (!cords_s)
		exit(EXIT_FAILURE);
	while (map[i])
	{
		cords_s[i] = ft_split((map[i]), ' ');
		if (!cords_s[i])
			exit (EXIT_FAILURE);
		i++;
	}
	cords_s[i] = 0;
	return (cords_s);
}
