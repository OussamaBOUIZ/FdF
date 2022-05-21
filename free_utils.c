/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 15:41:03 by obouizga          #+#    #+#             */
/*   Updated: 2022/05/20 15:43:59 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_both(char **s1, char **s2)
{
	free_double_p(s1);
	free_double_p(s2);
}

void	free_double_p(char **strings)
{
	char	**k;

	k = strings;
	while (*strings)
		free(*(strings++));
	free(k);
}
