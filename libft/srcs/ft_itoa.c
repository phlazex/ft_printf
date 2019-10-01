/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfahey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 16:34:56 by mfahey            #+#    #+#             */
/*   Updated: 2018/12/11 11:33:44 by mfahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_pos_len(int n)
{
	size_t	k;

	k = 0;
	while (n / 10 > 0)
	{
		k++;
		n /= 10;
	}
	return (++k);
}

static size_t	ft_neg_len(int n)
{
	size_t	k;

	k = 1;
	if (n == -2147483648)
		k = 11;
	else if (n < 0)
	{
		n = -n;
		while (n / 10 > 0)
		{
			k++;
			n /= 10;
		}
	}
	return (++k);
}

static char		*ft_itoc(int n, size_t k, char *str)
{
	str[k--] = '\0';
	if (n < 0)
	{
		if (n == -2147483648)
		{
			str[1] = '2';
			n %= 1000000000;
			k--;
		}
		n = -n;
	}
	while (n / 10 > 0)
	{
		str[k] = n % 10 + 48;
		n /= 10;
		k--;
	}
	str[k] = n + 48;
	return (str);
}

char			*ft_itoa(int n)
{
	char	*str;
	size_t	k;
	int		pn;

	k = 0;
	pn = 1;
	if (n < 0)
	{
		k += ft_neg_len(n);
		pn = -pn;
	}
	else
		k += ft_pos_len(n);
	if (!(str = (char*)malloc(sizeof(char) * (k + 1))))
		return (NULL);
	str = ft_itoc(n, k, str);
	if (pn < 0)
		str[0] = '-';
	return (str);
}
