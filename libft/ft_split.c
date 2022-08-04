/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouay <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 12:26:27 by adouay            #+#    #+#             */
/*   Updated: 2022/05/06 17:32:32 by adouay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_w_nbr(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		while (s[i] != '\0' && s[i] == c)
			i++;
		if (s[i] != '\0' && s[i] != c)
			count++;
		while (s[i] != '\0' && s[i] != c)
			i++;
	}
	return (count);
}

static int	ft_w_len(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && s[i] != c)
		i++;
	return (i);
}

static char	*ft_w(char const *s, char c)
{
	char	*word;
	int		w_len;
	int		i;

	i = 0;
	w_len = ft_w_len(s, c);
	word = malloc(sizeof(char) * w_len + 1);
	if (word == NULL)
		return (NULL);
	while (i < w_len)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**p;
	int		w_nbr;
	int		i;

	i = 0;
	w_nbr = ft_w_nbr(s, c);
	p = malloc(sizeof(char *) * (w_nbr + 1));
	if (p == NULL)
		return (NULL);
	while (*s != '\0' && i < w_nbr)
	{
		while (*s != '\0' && *s == c)
			s++;
		if (*s != '\0')
		{
			p[i] = ft_w(s, c);
			i++;
		}
		while (*s != '\0' && *s != c)
			s++;
	}
	p[i] = 0;
	return (p);
}
/*
int	main ()
{
	char	*str = "s a l u t mon piiipp i pote";
	char	c = ' ';
	char	**p;
	int	i;

	i = 0;
	p = ft_split(str, c);
	while (p[i])
	{
		printf("%s\n", p[i]);
		i++;
	}
	return (0);
}
*/
