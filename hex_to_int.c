/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_to_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 18:06:46 by obouizga          #+#    #+#             */
/*   Updated: 2022/05/30 18:29:08 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	hex_to_int(char *s)
{
	int	i;
	int	j;
	int	decim;
	int	b;
	int	l;

	decim = 0;
	j = 0;
	l = -1;
	i = ft_strlen(s) - 1;
	if (s[0] == '0' && s[1] == 'x')
		l = 1;
	while (i > l)
	{
		if (s[i] >= '0' && s[i] <= '9')
			b = s[i] - '0';
		else if (s[i] >= 'a' && s[i] <= 'f')
			b = s[i] - 'a' + 10;
		else if (s[i] >= 'A' && s[i] <= 'F')
			b = s[i] - 'A' + 10;
		decim = decim + b * pow(16, j);
		j++;
		i--;
	}
	return (decim);
}
