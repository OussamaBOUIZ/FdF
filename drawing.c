/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 15:07:23 by obouizga          #+#    #+#             */
/*   Updated: 2022/05/20 16:29:03 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"



void	drawing(t_iso **iso_tb, int *row_col, void *m_id, void *w_id)
{
	int	j;
	int	i;

	j = 0;
	while (j <= row_col[0] - 1)
	{
		i = -1;
		while (++i <= row_col[1] - 1)
		{
			if (i < row_col[1] - 1)
				plot_line(iso_tb[j][i].x, iso_tb[j][i].y, iso_tb[j][i + 1].x ,iso_tb[j][i + 1].y, m_id, w_id);
			if (j < row_col[0] - 1)
				plot_line(iso_tb[j][i].x, iso_tb[j][i].y, iso_tb[j + 1][i].x, iso_tb[j + 1][i].y, m_id, w_id);
		}
		j++;
	}
}