/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 15:07:23 by obouizga          #+#    #+#             */
/*   Updated: 2022/05/18 15:17:32 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	display_map(t_iso **iso_tb, int *row_col, void *m_id, void *w_id)
{
	int	j;
	int	i;

	j = 0;
	while (j < row_col[0] - 1)
	{
		i = -1;
		while (++i < row_col[1] - 1)
		{
			draw_line(iso_tb[j][i], iso_tb[j][i + 1], m_id, w_id);
			draw_line(iso_tb[j][i], iso_tb[j + 1][i], m_id, w_id);
		}
		j++;
	}
}
