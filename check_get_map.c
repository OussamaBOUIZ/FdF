/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_get_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 16:14:15 by obouizga          #+#    #+#             */
/*   Updated: 2022/05/27 19:36:42 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	manage_error(int ac, char **av)
{
	(void)av;
	if (ac != 2)
		exit(EXIT_FAILURE);
	if (-1 == open(av[1], O_RDWR))
	{
		ft_putstr("INVALID PATH ❌\n");
		exit(EXIT_FAILURE);
	}
}

int	d_str_len(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	check_map(char **map)
{
	int		i;
	char	**s1;
	char	**s2;

	i = 0;
	while (map[i + 1])
	{
		s1 = ft_split(map[i], ' ');
		s2 = ft_split(map[i + 1], ' ');
		if (d_str_len(s1) != d_str_len(s2))
		{
			free_both(s1, s2);
			ft_putstr("The map is NOT valid! ❌\n");
			return (1);
		}
		free_both(s1, s2);
		i++;
	}
	ft_putstr("The map is SUPER valid! ✅\n");
	return (0);
}

char	**check_get_map(int ac, char **av)
{
	char	**map;

	manage_error(ac, av);
	map = read_map(av[1]);
	if (check_map(map))
	{
		free_double_p(map);
		exit(EXIT_FAILURE);
	}
	return (map);
}
