/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouay <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 00:09:17 by adouay            #+#    #+#             */
/*   Updated: 2022/06/30 14:55:52 by adouay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_clean_container(char *container)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (container[i] && container[i] != '\n')
		i++;
	if (!container[i])
	{
		free (container);
		return (NULL);
	}
	new = malloc(sizeof(char) * (ft_strlen(container) - i + 1));
	if (!new)
	{
		free (container);
		return (NULL);
	}
	i++;
	while (container[i] != '\0')
		new[j++] = container[i++];
	new[j] = '\0';
	free(container);
	return (new);
}

char	*ft_get_line(char *container)
{
	char	*line;
	int		n;
	int		i;

	n = 0;
	i = 0;
	if (container[0] == '\0')
		return (NULL);
	while (container[n] != '\n' && container[n] != '\0')
		n++;
	line = malloc(sizeof(char) * n + 2);
	if (!line)
		return (NULL);
	while (container[i] != '\n' && container[i] != '\0')
	{
		line[i] = container[i];
		i++;
	}
	if (container[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*ft_full(int fd, char *container)
{
	char	*buff;
	int		n;

	n = 1;
	buff = malloc(sizeof(char) * (10 + 1));
	if (!buff)
		return (NULL);
	while (!ft_strchr(container, '\n') && n != 0)
	{
		n = read(fd, buff, 10);
		if (n < 0)
		{
			free (buff);
			return (NULL);
		}
		buff[n] = '\0';
		container = ft_strjoin_pimped(container, buff);
	}
	free (buff);
	return (container);
}

char	*get_next_line(int fd)
{
	static char	*container[1024];
	char		*line;

	if (fd < 0 || 10 <= 0)
		return (0);
	container[fd] = ft_full(fd, container[fd]);
	if (container[fd] == NULL)
		return (NULL);
	line = ft_get_line(container[fd]);
	container[fd] = ft_clean_container(container[fd]);
	return (line);
}
