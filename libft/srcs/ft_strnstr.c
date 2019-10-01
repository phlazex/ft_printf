/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfahey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 11:22:16 by mfahey            #+#    #+#             */
/*   Updated: 2018/12/11 19:39:26 by mfahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str1;
	char	*str2;

	str1 = (char*)haystack;
	str2 = (char*)needle;
	i = 0;
	if (str2[i] == 0)
		return (str1);
	while ((str1[i] != '\0') && (i < len))
	{
		j = 0;
		while ((str2[j] == str1[i + j]) && ((i + j) < len))
		{
			if (str2[j + 1] == '\0')
				return (str1 + i);
			j++;
		}
		i++;
	}
	return (NULL);
}
