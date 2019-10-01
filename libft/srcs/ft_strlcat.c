/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfahey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 17:37:17 by mfahey            #+#    #+#             */
/*   Updated: 2019/02/14 18:56:25 by mfahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = ft_strlen(dst);
	k = ft_strlen(src);
	j = 0;
	while ((src[j]) && ((j + i + 1) < size))
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = '\0';
	return (k + (size_t)(ft_min((long long)i, (long long)size)));
}
