/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouay <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 12:13:55 by adouay            #+#    #+#             */
/*   Updated: 2022/05/06 00:46:23 by adouay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	c = 'W';
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		n = -n;
		write (fd, "-", 1);
	}
	if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		n = n % 10;
	}
	c = n + 48;
	write (fd, &c, 1);
}
/*
int main()
{
	int fd;

	fd = open("test.txt", O_WRONLY);
	ft_putnbr_fd(-42, fd);
	return(0);
}
*/
