/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 09:06:03 by obouizga          #+#    #+#             */
/*   Updated: 2022/06/03 15:23:34 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	if (!str)
		return (0);
	while (str[len])
		len++;
	return (len);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*nw_str;
	size_t	total_l;
	int		i;
	int		j;

	total_l = ft_strlen(s1) + ft_strlen(s2);
	nw_str = malloc(sizeof(char) * (total_l + 1));
	if (!nw_str)
		return (NULL);
	i = -1;
	if (s1)
		while (s1[++i])
			nw_str[i] = s1[i];
	j = ft_strlen(s1);
	i = 0;
	if (s2)
		while (s2[i])
			nw_str[j++] = s2[i++];
	nw_str[j] = '\0';
	free(s1);
	return (nw_str);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;

	i = 0;
	if (len == 0)
		substr = (char *) malloc(sizeof(char) * 1);
	else
	{
		if (!s || !len)
			return (NULL);
		if (start >= ft_strlen(s))
			len = 0;
		else if (len > ft_strlen(s))
			len = ft_strlen(s) - start;
		substr = malloc((len + 1) * sizeof(char));
		if (!substr)
			return (NULL);
		while (s[start] && i < len)
			substr[i++] = s[start++];
	}
	substr[i] = 0;
	return (substr);
}

char	*ft_strdup(char *s1)
{
	int		a;
	char	*copy;
	char	*s;

	if (!s1)
		return (NULL);
	a = 0;
	s = (char *)s1;
	copy = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!copy)
		exit(EXIT_FAILURE);
	while (s[a])
	{
		copy[a] = s[a];
		a++;
	}
	copy[a] = '\0';
	return (copy);
}
