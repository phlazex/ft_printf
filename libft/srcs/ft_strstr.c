/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfahey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 20:14:44 by mfahey            #+#    #+#             */
/*   Updated: 2018/11/30 21:14:38 by mfahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
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
	while (str1[i] != '\0')
	{
		j = 0;
		while (str2[j] == str1[i + j] && str1[i + j])
		{
			if (str2[j + 1] == 0)
				return (str1 + i);
			j++;
		}
		i++;
	}
	return (NULL);
}
