/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouay <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 11:32:30 by adouay            #+#    #+#             */
/*   Updated: 2022/05/04 11:33:44 by adouay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	while (n--)
		*d++ = *s++;
	return (dest);
}
/*
int	main()
{
	char dest[20] ="qsdfghjklm";
	char dest2[20] ="qsdfghjklm";
	char src[] = "salut mec";

//	memcpy(src, src + 2, 5);
	ft_memcpy(src, src + 2, 5);

	printf("%s\n", src);
	printf("%s\n", src);
	return(0);
}*/
