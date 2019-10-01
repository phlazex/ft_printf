/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llitoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfahey <mfahey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 17:55:37 by mfahey            #+#    #+#             */
/*   Updated: 2019/06/13 21:28:15 by mfahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define N 4611686018427387904

static char			*ft_ulltoa(char *str, unsigned long long n,
		unsigned long long base, size_t *l)
{
	char				*tab;

	tab = "0123456789abcdefghijklmnopqrstuvwxyz";
	str[(l[0])--] = '\0';
	n += l[2];
	while ((n / base) > 0)
	{
		str[l[0]] = tab[(n % base)];
		n /= base;
		(l[0])--;
	}
	str[l[0]] = tab[n];
	if (l[1])
		str[0] = '-';
	return (str);
}

static long long	ft_length_n(long long n, long long base)
{
	size_t				l;

	l = 0;
	while ((n / base) > 0)
	{
		l++;
		n /= base;
	}
	return (++l);
}

char				*ft_llitoa_base(long long n, int base)
{
	char				*str;
	size_t				l[3];

	str = NULL;
	l[0] = 0;
	l[1] = 0;
	l[2] = 0;
	if (((base >= 2) && (base <= 36)) && ((n >= -2 * N) && (n <= (N - 1 + N))))
	{
		if (n < 0)
		{
			if (n == -2 * N)
				(l[2])++;
			n += (long long)(l[2]);
			(l[1])++;
			n = -n;
			(l[0])++;
		}
		(l[0]) += ft_length_n(n, (long long)base);
		if (!(str = (char *)malloc(sizeof(char) * ((l[0]) + 1))))
			return (NULL);
		str = ft_ulltoa(str, (unsigned long long)n,
				(unsigned long long)base, l);
	}
	return (str);
}
