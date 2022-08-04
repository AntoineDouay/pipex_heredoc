/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouay <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 12:40:15 by adouay            #+#    #+#             */
/*   Updated: 2022/05/05 22:48:50 by adouay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	char	*p;
	int		n;

	n = ft_strlen(s);
	p = malloc(sizeof(char) * n + 1);
	if (p == NULL)
		return (NULL);
	i = 0;
	while (i < n)
	{
		p[i] = s[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}
/*
int	main()
{
	char *src ="qwqewefewfwe";
	printf("%s\n", ft_strdup(src));
}
*/
