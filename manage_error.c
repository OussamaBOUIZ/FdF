/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 08:08:30 by obouizga          #+#    #+#             */
/*   Updated: 2022/05/12 09:45:24 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	manage_error(int ac, char **av)
{
	(void)av;
	if (ac != 2)
		exit(EXIT_FAILURE);
	if (-1 == open(av[1], O_RDONLY))
		exit(EXIT_FAILURE);
}
