/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouay <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 20:31:28 by adouay            #+#    #+#             */
/*   Updated: 2022/05/04 22:50:52 by adouay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*last;

	last = NULL;
	if (c == 0)
		return (ft_strchr(s, c));
	while (*s)
	{
		if (*s == (char)c)
			last = (char *)s;
		s++;
	}	
	return (last);
}
/*
int	main()
{
	char *s = "salut mon pote";
	printf("%s\n", ft_strrchr(s, 111));
	return (0);
}
*/
