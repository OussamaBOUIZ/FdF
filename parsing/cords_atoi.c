/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cords_atoi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 07:54:07 by obouizga          #+#    #+#             */
/*   Updated: 2022/09/30 16:16:55 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

t_iso	**iso_square(int row, int col)
{
	t_iso	**iso_tab;
	int		i;

	iso_tab = malloc(sizeof(t_iso *) * (row + 1));
	if (!iso_tab)
		exit(EXIT_FAILURE);
	i = 0;
	while (i < row)
	{
		iso_tab[i] = malloc(sizeof(t_iso) * col);
		if (!iso_tab[i])
			exit(EXIT_FAILURE);
		i++;
	}
	iso_tab[i] = 0;
	return (iso_tab);
}

void	get_perimeter(t_peri *peri, int x, int y)
{
	if (x > peri->max_x)
		peri->max_x = x;
	if (x <= peri->min_x)
		peri->min_x = x;
	if (y > peri->max_y)
		peri->max_y = y;
	if (y <= peri->min_y)
		peri->min_y = y;
}

t_peri	*new_perim(void)
{
	t_peri	*perim;

	perim = malloc(sizeof(t_peri));
	if (!perim)
		return (0);
	perim->max_x = 0;
	perim->max_y = 0;
	perim->min_x = 0;
	perim->min_y = 0;
	return (perim);
}

t_sh	cords_atoi(char ***cor, int *dim, char **map)
{
	t_sh	sh;
	int		i;
	int		j;
	t_peri	*perim;
	t_u		units;

	j = 0;
	i = 0;
	sh.iso = iso_square(dim[0], dim[1]);
	perim = new_perim();
	units = def_unit(dim, map, cor);
	while (cor[j])
	{
		i = 0;
		while (cor[j][i])
		{
			sh.iso[j][i] = to_isom((t_d)i, (t_d)j, s_atoi(cor[j][i]), units);
			get_perimeter(perim, sh.iso[j][i].x, sh.iso[j][i].y);
			i++;
		}
		j++;
	}
	sh.peri = *perim;
	free(perim);
	return (sh);
}
