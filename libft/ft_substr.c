/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouay <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 20:36:12 by adouay            #+#    #+#             */
/*   Updated: 2022/05/06 22:19:26 by adouay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	slen;
	char	*p;

	i = 0;
	slen = ft_strlen(s);
	if (start > slen)
	{
		p = ft_calloc(1, sizeof(char));
		return (p);
	}
	if (start + len > slen)
		len = slen - start;
	p = ft_calloc(len + 1, sizeof(char));
	while (s[start] && i < len)
	{
		p[i] = s[start];
		start++;
		i++;
	}
	return (p);
}
/*
int	main()
{
	char *str = "salut les gars";
	char *cpy = ft_substr(str, 3, 5);
	printf("%s\n", cpy);
	free(cpy);
}
*/
