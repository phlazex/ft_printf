/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfahey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 18:26:21 by mfahey            #+#    #+#             */
/*   Updated: 2018/12/06 20:38:37 by mfahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_start_ind(char const *s)
{
	size_t	i;

	i = 0;
	while ((s[i] == ' ') || (s[i] == '\t') || (s[i] == '\n'))
		i++;
	return (i);
}

static size_t	ft_end_ind(char const *s)
{
	size_t	len;

	len = ft_strlen(s) - 1;
	while ((s[len] == ' ') || (s[len] == '\t') || (s[len] == '\n'))
		len--;
	return (++len);
}

char			*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	*str;

	if (!s)
		return (NULL);
	j = 0;
	i = ft_start_ind(s);
	len = ft_end_ind(s);
	if (((int)len - (int)i) >= 0)
	{
		if (!(str = (char*)malloc(sizeof(char) * (len - i + 1))))
			return (NULL);
		while (i < len)
			str[j++] = s[i++];
	}
	else if (!(str = (char*)malloc(sizeof(char) * 1)))
		return (NULL);
	str[j] = '\0';
	return (str);
}
