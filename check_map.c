/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 08:38:58 by obouizga          #+#    #+#             */
/*   Updated: 2022/05/12 10:53:13 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_double_p(char **strings)
{
	char	**k;

	k = strings;
	while (*strings)
		free(*(strings++));
	free(k);
}

void	free_both(char **s1, char **s2)
{
	free_double_p(s1);
	free_double_p(s2);
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
