/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfahey <mfahey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 18:05:19 by mfahey            #+#    #+#             */
/*   Updated: 2019/08/18 22:27:47 by mfahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_isprecision(t_printf *ft)
{
	if ((ft->fmt)[ft->i] == '.')
	{
		ft->precision = 0;
		while ((ft->fmt)[ft->i] == '.')
			(ft->i)++;
		if ((ft->fmt)[ft->i] == '*')
		{
			ft->precision = va_arg(ft->ap, int);
			(ft->i)++;
		}
		else if (ft_isdigit(ft->fmt[ft->i]))
		{
			ft->precision = (int)ft_atoll(ft->fmt + ft->i);
			while (ft_isdigit((ft->fmt)[ft->i]))
				(ft->i)++;
		}
		if (ft->precision < 0)
			ft->precision = 0;
		else
			(ft->prec)++;
	}
}
