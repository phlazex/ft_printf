/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoull.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfahey <mfahey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 18:48:24 by mfahey            #+#    #+#             */
/*   Updated: 2019/06/12 19:48:24 by mfahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long long	ft_atoull(const char *str)
{
	size_t				i;
	unsigned long long	n;

	i = 0;
	while (ft_isspace(str[i]))
		i++;
	n = 0;
	while (ft_isdigit(str[i]))
	{
		n = n * 10 + (str[i] - 48);
		i++;
	}
	return (n);
}
