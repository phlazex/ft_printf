/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfahey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 15:34:45 by mfahey            #+#    #+#             */
/*   Updated: 2018/12/11 18:59:18 by mfahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	sb;
	size_t			i;

	i = 0;
	sb = (unsigned char)c;
	str = (unsigned char*)s;
	while (i < n)
	{
		if (str[i] == sb)
			return ((void*)str + i);
		i++;
	}
	return (NULL);
}
