/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfahey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 20:12:33 by mfahey            #+#    #+#             */
/*   Updated: 2018/12/01 21:32:59 by mfahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_move_za(unsigned char *str1, unsigned char *str2, size_t len)
{
	while (len > 0)
	{
		str1[len - 1] = str2[len - 1];
		len--;
	}
}

static void	ft_move_az(unsigned char *str1, unsigned char *str2, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		str1[i] = str2[i];
		i++;
	}
}

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char*)dst;
	str2 = (unsigned char*)src;
	if (dst > src)
		ft_move_za(str1, str2, len);
	else
		ft_move_az(str1, str2, len);
	return (dst);
}
