/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouay <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 23:17:51 by adouay            #+#    #+#             */
/*   Updated: 2022/05/04 21:55:57 by adouay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*p;

	c = c % 256;
	p = (char *)s;
	while (n--)
	{
		if (*p != c)
			p++;
		else
			return (p);
	}
	return (0);
}
/*
int main()
{
    char *str = "salut les gars";
    char c = 'l';
    size_t s = 100;
    
    void *m = memchr(str, (int)c, s);
    void *ft_m = ft_memchr(str, (int)c, s);
    printf("%s\n", (char *)m);
    printf("%s\n", (char *)ft_m);

    return (0);
}
*/
