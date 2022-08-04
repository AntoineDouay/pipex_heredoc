/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouay <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 13:30:51 by adouay            #+#    #+#             */
/*   Updated: 2022/06/30 14:46:35 by adouay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	char	*p;

	i = 0;
	p = malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!p)
		return (NULL);
	while (*s1)
	{
		p[i] = *s1;
		i++;
		s1++;
	}
	while (*s2)
	{
		p[i] = *s2;
		i++;
		s2++;
	}
	p[i] = '\0';
	return (p);
}

/*
int	main()
{
	char *p;

	p = ft_strjoin("salt", " gars");
	printf ("%s\n", p);
	free (p);
	return (0);
}
*/
