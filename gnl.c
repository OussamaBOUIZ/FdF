/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 09:04:52 by obouizga          #+#    #+#             */
/*   Updated: 2022/05/12 08:14:47 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static char	*before_bn(char *buff)
{
	int		i;

	if (!*buff)
		return (NULL);
	i = 0;
	while (buff[i] && buff[i] != '\n')
		i++;
	return (ft_substr(buff, 0, i + 1));
}

static char	*after_bn(char *buff)
{
	char	*after;
	int		len;
	int		i;

	len = ft_strlen(buff);
	i = 0;
	while (buff[i])
	{
		if (buff[i] == '\n')
		{
			after = ft_substr(buff, i + 1, len - i + 1);
			free(buff);
			return (after);
		}
		i++;
	}
	free(buff);
	return (NULL);
}

static int	backslash_n(char *buff)
{
	if (!buff)
		return (0);
	while (*buff)
	{
		if (*buff == '\n')
			return (1);
		buff++;
	}
	return (0);
}

static char	*read_file(int fd, char *red)
{
	int		i;
	char	*buff;

	i = 1;
	buff = malloc (sizeof(char) * (B_S + 1));
	if (!buff)
		return (NULL);
	while (!backslash_n(red) && i)
	{
		i = read(fd, buff, B_S);
		if (i == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[i] = 0;
		red = ft_strjoin(red, buff);
	}
	free(buff);
	return (red);
}

char	*get_next_line(int fd)
{
	static char	*red;
	char		*line;

	if (B_S <= 0 || fd < 0)
		return (NULL);
	red = read_file(fd, red);
	if (!red)
		return (NULL);
	line = before_bn(red);
	red = after_bn(red);
	return (line);
}
