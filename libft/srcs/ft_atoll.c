/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfahey <mfahey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 18:48:24 by mfahey            #+#    #+#             */
/*   Updated: 2019/06/12 19:05:46 by mfahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	ft_atoll(const char *str)
{
	size_t		i;
	long long	pn;
	long long	n;

	i = 0;
	while (ft_isspace(str[i]))
		i++;
	pn = 1;
	if ((str[i] == '-') || (str[i] == '+'))
	{
		if (str[i] == '-')
			pn = -pn;
		i++;
	}
	n = 0;
	while (ft_isdigit(str[i]))
	{
		n = n * 10 + (str[i] - 48);
		i++;
	}
	return (n * pn);
}
