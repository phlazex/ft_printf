/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfahey <mfahey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 17:15:51 by mfahey            #+#    #+#             */
/*   Updated: 2019/09/30 17:49:13 by mfahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_atof_printf_frst(t_printf *ft, unsigned long long k, size_t i)
{
	ft->srpf = (char *)malloc(sizeof(char) * (ft->precision) + 1);
	(ft->srpf)[i + 1] = '\0';
	while (i > 0)
	{
		(ft->srpf)[i] = (int)(k % 10) + 48;
		k /= 10;
		i--;
	}
	if (ft->precision || ft->flag->sharp)
		(ft->srpf)[i] = '.';
	else
		(ft->srpf)[i] = '\0';
	ft->lpf += (long double)k;
	(ft->slpf) = ft_ulltoa_base(ft->lpf, 10);
	ft->ss = ft_strjoin(ft->slpf, ft->srpf);
	ft->length = ft_strlen(ft->ss);
}

void	ft_atof_printf(t_printf *ft)
{
	unsigned long long	k;
	size_t				i;

	i = 0;
	while (i < ft->precision)
	{
		ft->rpf *= 10.;
		i++;
	}
	k = (unsigned long long)(ft->rpf);
	ft->rpf -= (long double)k;
	if (((ft->rpf) * 10.) >= 5.)
		k++;
	ft_atof_printf_frst(ft, k, i);
	ft_strdel(&(ft->slpf));
	ft_strdel(&(ft->srpf));
}
