/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 11:56:48 by obouizga          #+#    #+#             */
/*   Updated: 2022/05/14 15:39:05 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_iso	to_isometric(t_cart cart)
{
	t_iso	iso;

	iso.x = cart.x - cart.y;
	iso.y = ((cart.x + cart.y) / 2) - cart.z;
	return (iso);
}

int	main(int ac, char **av)
{
	t_cart	cart;
	t_iso	iso;

	if (ac > 4 && ac <= 2)
		return (1);
	cart.x = ft_atoi(av[1]);
	cart.y = ft_atoi(av[2]);
	if (ac == 4)
		cart.z = ft_atoi(av[3]);
	iso = to_isometric(cart);
	printf("( x : %.1f, y : %.1f)\n", iso.x, iso.y);
	return (0);
}
