/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouay <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 20:57:57 by adouay            #+#    #+#             */
/*   Updated: 2022/05/04 21:05:51 by adouay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	int_len(int n)
{
	long int	nb;
	int			len;

	nb = n;
	len = 0;
	if (nb < 0)
	{
		nb = -nb;
		len++;
	}
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char		*p;
	int			len;
	long int	nb;

	len = int_len(n);
	nb = n;
	p = malloc(sizeof(char) * (len + 1));
	if (!p)
		return (NULL);
	p[len] = '\0';
	len--;
	if (nb < 0)
	{
		p[0] = '-';
		nb = -nb;
	}
	if (nb == 0)
		p[0] = '0';
	while (nb > 0)
	{
		p[len] = (nb % 10) + 48;
		nb /= 10;
		len--;
	}
	return (p);
}
/*
int	main()
{
	printf("%s\n", ft_itoa(2147483647));
}
*/
