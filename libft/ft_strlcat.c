/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouay <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 13:49:50 by adouay            #+#    #+#             */
/*   Updated: 2022/05/06 00:46:58 by adouay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dlen;
	size_t	slen;
	size_t	i;

	dlen = ft_strlen(dst);
	slen = ft_strlen(src);
	i = 0;
	if (size <= dlen)
		return (size + slen);
	while (src[i] != '\0' && dlen < (size - 1))
	{
		dst[dlen] = src[i];
		dlen++;
		i++;
	}
	dst[dlen] = '\0';
	return ((dlen - i) + slen);
}
/*
int	main()
{
	char dest[100] = "salut";
	char *src = "loulotgrgr";
	size_t size = ft_strlcat(dest, src, 100);
	printf("%s\n", dest);
	printf("%ld\n", size);
	return (0);
}
*/
