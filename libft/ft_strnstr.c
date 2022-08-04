/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouay <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 20:26:15 by adouay            #+#    #+#             */
/*   Updated: 2022/05/05 22:50:05 by adouay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;

	i = 0;
	if (ft_strlen(little) == 0)
		return ((char *)big);
	while (big[i] && i < len)
	{
		if (ft_strncmp(big + i, little, ft_strlen(little)) == 0
			&& (ft_strlen(little) + i) <= len)
			return ((char *)big + i);
		i++;
	}
	return (NULL);
}
/*int main()
{
    char *big = "aaabcabcd";
    char *little = "abcd";
    //printf("%s\n", strnstr(big, little, 5));
    printf("%s\n", ft_strnstr(big, little, -1));
    return (0);
}*/
