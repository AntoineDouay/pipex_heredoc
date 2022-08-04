/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouay <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 11:45:57 by adouay            #+#    #+#             */
/*   Updated: 2022/05/06 17:19:07 by adouay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_start_index(char const *s1, char const *set)
{
	int	count;

	count = 0;
	while (*s1 && ft_strchr(set, *s1))
	{
		count++;
		s1++;
	}
	return (count);
}

static int	ft_end_index(char const *s1, char const *set)
{
	int	len;

	len = ft_strlen(s1) - 1;
	while (s1[len] != '\0' && ft_strchr(set, s1[len]))
		len--;
	return (len);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	int		i;
	char	*p;

	if (!s1 || !set)
		return (NULL);
	start = ft_start_index(s1, set);
	end = ft_end_index(s1, set);
	i = 0;
	if (end - start < 0)
		return (ft_strdup(""));
	p = malloc(sizeof(char) * (end - start + 2));
	if (!p)
		return (NULL);
	while (i <= (end - start))
	{
		p[i] = s1[start + i];
		i++;
	}
	p[i] = '\0';
	return (p);
}
/*
int	main ()
{

	char	*str = "abcdba";
	char	*set = "abc";
	char 	*p = ft_strtrim(str, set);
	printf ("%s\n", p);
	free (p);
	return (0);








}*/
