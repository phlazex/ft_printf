/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfahey <mfahey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 17:55:37 by mfahey            #+#    #+#             */
/*   Updated: 2019/06/13 21:39:03 by mfahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_ulltoa(char *str, unsigned long long n,
		unsigned long long base, size_t l)
{
	char	*tab;

	tab = "0123456789abcdefghijklmnopqrstuvwxyz";
	str[l--] = '\0';
	while ((n / base) > 0)
	{
		str[l] = tab[(n % base)];
		n /= base;
		l--;
	}
	str[l] = tab[n];
	return (str);
}

static size_t	ft_length_n(unsigned long long n,
		unsigned long long base)
{
	size_t	l;

	l = 0;
	while ((n / base) > 0)
	{
		l++;
		n /= base;
	}
	return (++l);
}

char			*ft_ulltoa_base(unsigned long long n, int base)
{
	char	*str;
	size_t	l;

	str = NULL;
	l = 0;
	if (((base >= 2) && (base <= 36)))
	{
		l += ft_length_n(n, (unsigned long long)base);
		if (!(str = (char *)malloc(sizeof(char) * (l + 1))))
			return (NULL);
		str = ft_ulltoa(str, n, (unsigned long long)base, l);
	}
	return (str);
}
