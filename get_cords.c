/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cords.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 16:29:56 by obouizga          #+#    #+#             */
/*   Updated: 2022/05/16 16:55:25 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	***get_cords(char **map, int col, int row)
{
	char	***cords_s;

	cords_s = malloc(sizeof(char **) * row);
	if (!cords_s)
		return (NULL);
	while (*map)
	{
		cords_s = ft_split(*map, ' ');
		map++;
	}
	return (cords_s);
}
