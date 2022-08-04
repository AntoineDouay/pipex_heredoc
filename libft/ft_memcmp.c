/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouay <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 11:27:50 by adouay            #+#    #+#             */
/*   Updated: 2022/05/04 11:30:04 by adouay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str;
	unsigned char	*str2;

	str = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (n--)
	{
		if (*str != *str2)
			return (*str - *str2);
		else
		{
			str++;
			str2++;
		}
	}
	return (0);
}
/*
int main()
{
    char *s1 = "salut mon pote";
    char *s2 = "salut mon pote";
    printf("%d\n", memcmp(s1, s2, 6));
    printf("%d\n", ft_memcmp(s1, s2, 6));
    return(0);
}
*/
