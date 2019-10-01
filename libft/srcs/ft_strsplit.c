/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfahey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 14:51:54 by mfahey            #+#    #+#             */
/*   Updated: 2018/12/12 14:01:45 by mfahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_n(char const *s, char c, size_t i)
{
	size_t	n;

	n = 0;
	while ((s[i] != '\0') && (s[i] != c))
	{
		i++;
		n++;
	}
	return (n);
}

static size_t	ft_m(char const *s, char c)
{
	size_t	m;
	size_t	i;

	m = 0;
	i = 0;
	while (s[i] != '\0')
		if (s[i] == c)
			i++;
		else
		{
			m++;
			while ((s[i] != c) && (s[i] != '\0'))
				i++;
		}
	return (m);
}

static char		*ft_str(char const *s, char c, size_t *i)
{
	size_t	k;
	char	*str;

	if (!(str = (char*)malloc(sizeof(char) * (ft_n(s, c, *i) + 1))))
		return (NULL);
	else
	{
		k = 0;
		while ((s[*i] != '\0') && (s[*i] != c))
			str[k++] = s[(*i)++];
		str[k] = '\0';
	}
	return (str);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	i;
	size_t	j;
	char	**str;

	if (!s || !c)
		return (NULL);
	if (!(str = (char**)malloc(sizeof(char*) * (ft_m(s, c) + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		while ((s[i] == c) && (s[i] != '\0'))
			i++;
		while ((s[i] != '\0') && (s[i] != c))
		{
			if ((str[j++] = ft_str(s, c, &i)) == NULL)
				return (NULL);
		}
	}
	str[j] = NULL;
	return (str);
}
