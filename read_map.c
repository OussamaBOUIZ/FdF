/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 09:13:56 by obouizga          #+#    #+#             */
/*   Updated: 2022/05/30 19:29:38 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	**read_map(char *file)
{
	int		fd;
	char	*map_s;
	char	*next_l;
	char	**map;

	fd = open(file, O_RDONLY);
	map_s = get_next_line(fd);
	if (!map_s)
	{
		ft_putstr("🚨 EMPTY FILE\n");
		exit(EXIT_FAILURE);
	}
	next_l = get_next_line(fd);
	while (next_l)
	{
		map_s = ft_strjoin(map_s, next_l);
		free(next_l);
		next_l = get_next_line(fd);
	}
	map = ft_split(map_s, '\n');
	free(map_s);
	return (map);
}
