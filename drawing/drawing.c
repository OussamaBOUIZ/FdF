/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 15:07:23 by obouizga          #+#    #+#             */
/*   Updated: 2022/09/30 16:16:55 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

t_off	cal_offset(t_sh sh)
{
	int		xc;
	int		yc;
	t_off	offset;

	xc = (int)((sh.peri.max_x + sh.peri.min_x) / 2);
	yc = (int)((sh.peri.max_y + sh.peri.min_y) / 2);
	offset.x_off = W_W / 2 - xc;
	offset.y_off = W_H / 2 - yc;
	return (offset);
}

void	drawing(t_sh sh, int *row_col, t_data *img)
{
	int		j;
	int		i;
	t_off	offset;

	j = 0;
	offset = cal_offset(sh);
	while (j <= row_col[0] - 1)
	{
		i = 0;
		while (i <= row_col[1] - 1)
		{
			if (i < row_col[1] - 1)
				plot_line(sh.iso[j][i], sh.iso[j][i + 1], img, offset);
			if (j < row_col[0] - 1)
				plot_line(sh.iso[j][i], sh.iso[j + 1][i], img, offset);
			i++;
		}
		j++;
	}
	free_double_iso(sh.iso);
	free(row_col);
}