/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_atoi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 18:07:22 by obouizga          #+#    #+#             */
/*   Updated: 2022/05/30 18:32:11 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_atoi	s_atoi(char *str)
{
	int		i;
	t_atoi	zee;
	int		sign;

	i = 0;
	zee.val = 0;
	zee.clr = COLOR;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{	
		zee.val = zee.val * 10 + str[i] - '0';
		i++;
	}
	if (str[i] == ',')
		zee.clr = hex_to_int(&str[i + 1]);
	zee.val *= sign;
	return (zee);
}
