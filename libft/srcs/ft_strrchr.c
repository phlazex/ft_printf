/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfahey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 19:50:54 by mfahey            #+#    #+#             */
/*   Updated: 2018/12/11 20:22:45 by mfahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	j;
	size_t	i;

	i = 0;
	j = 0;
	while (s[i] != 0)
	{
		if (s[i] == (char)c)
			j = i;
		i++;
	}
	if (s[i] == (char)c)
		return ((char*)(s + i));
	if (s[j] == (char)c)
		return ((char*)(s + j));
	return (NULL);
}
