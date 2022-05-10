/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 06:53:31 by obouizga          #+#    #+#             */
/*   Updated: 2022/05/09 08:05:44 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	if (s)
		while (*s)
			ft_putchar(*(s++));
}

void	ft_putnbr(int nb)
{
	long int	b;

	b = nb;
	if (b < 0)
	{
		ft_putchar('-');
		b = b * (-1);
	}
	if (b >= 10)
	{
		ft_putnbr(b / 10);
	}
	ft_putchar(b % 10 + '0');
}
