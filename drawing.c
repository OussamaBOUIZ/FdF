/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 15:07:23 by obouizga          #+#    #+#             */
/*   Updated: 2022/05/23 19:26:04 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//ORIGINAL
// void	drawing(t_iso **iso_tb, int *row_col, void **mlx)
// {
// 	int	j;
// 	int	i;

// 	j = 0;
// 	while (j <= row_col[0] - 1)
// 	{
// 		i = -1;
// 		while (++i <= row_col[1] - 1)
// 		{
// 			if (i < row_col[1] - 1)
// 				plot_line(iso_tb[j][i], iso_tb[j][i + 1], mlx);
// 			if (j < row_col[0] - 1)
// 				plot_line(iso_tb[j][i], iso_tb[j + 1][i], mlx);
// 		}
// 		j++;
// 	}
// }
//TESTING

void	drawing(t_iso **iso_tb, int *row_col, t_data *img)
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
				plot_line(iso_tb[j][i], iso_tb[j][i + 1], img);
			if (j < row_col[0] - 1)
				plot_line(iso_tb[j][i], iso_tb[j + 1][i], img);
		}
		j++;
	}
}
