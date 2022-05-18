/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cords.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 16:29:56 by obouizga          #+#    #+#             */
/*   Updated: 2022/05/17 16:30:56 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
//The value of row should be equal to length of map
char	***get_cords(char **map, int row)
{
	char	***cords_s;
	int		i;

	i = 0;
	cords_s = malloc(sizeof(char **) * (row + 1));
	if (!cords_s)
		return (NULL);
	while (*map)
		cords_s[i++] = ft_split(*(map++), ' ');
	cords_s[i] = 0;
	return (cords_s);
}
