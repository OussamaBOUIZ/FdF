/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_err.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 17:29:40 by obouizga          #+#    #+#             */
/*   Updated: 2022/09/30 17:30:06 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	win_id_error(void *w_id)
{
	ft_putstr("Error occured in mlx_new_window()\n");
	free(w_id);
	exit(EXIT_FAILURE);
}

void	mlx_id_error(void)
{
	ft_putstr("Error occured in mlx_init()\n");
	exit(EXIT_FAILURE);
}

void	image_error(void *img)
{
	ft_putstr("Error occured in mlx_new_image()\n");
	free(img);
	exit(EXIT_FAILURE);
}

void	get_data_addr_error(char *ad)
{
	ft_putstr("Error occured in mlx_get_data_addr()\n");
	free(ad);
	exit(EXIT_FAILURE);
}