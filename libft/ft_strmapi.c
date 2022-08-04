/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouay <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 17:32:08 by adouay            #+#    #+#             */
/*   Updated: 2022/05/04 18:32:09 by adouay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
char f(unsigned int i, char c)
{
	char str;
	str = c + i;
	return (str);
}
*/
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	size_t	len;
	char	*p;

	i = 0;
	len = ft_strlen(s);
	if (!s || !f)
		return (NULL);
	p = malloc(sizeof(char) * (len + 1));
	if (!p)
		return (0);
	while (i < len)
	{
		p[i] = (*f)(i, s[i]);
		i++;
	}
	p[i] = '\0';
	return (p);
}
/*
int main()
{
	char str1[] = "\0";
	char* str2;
	str2 = ft_strmapi(str1, *f);
	printf("%s\n", str2);
	free(str2);
	return (0);
}
*/
