/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfahey <mfahey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 18:01:19 by mfahey            #+#    #+#             */
/*   Updated: 2019/09/30 16:04:22 by mfahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_search_deafault(t_printf *ft)
{
	ft->rpf = 0.0;
	ft->lpf = 0.0;
	ft->exp = 0.0;
	ft->pn = 0;
	ft->prec = 0;
	ft->k = 0;
	ft->flag->sharp = 0;
	ft->flag->zero = 0;
	ft->flag->minus = 0;
	ft->flag->space = 0;
	ft->flag->plus = 0;
	ft->width = 0;
	ft->precision = 0;
	ft->size = ws;
	ft->type = wt;
	ft->percent = 0;
}

void	ft_search(t_printf *ft)
{
	while ((ft->fmt)[ft->i] != '\0')
	{
		ft_isflag(ft);
		ft_iswidth(ft);
		ft_isprecision(ft);
		ft_issize(ft);
		ft_istype(ft);
		if ((ft->type) || (ft->percent))
			break ;
		else if (!(ft_isflag_frst(ft, (ft->fmt)[ft->i])) &&
				!(ft_isdigit((ft->fmt)[ft->i])) && !((ft->fmt)[ft->i] == '*')
				&& !((ft->fmt)[ft->i] == '.') &&
				!(ft_issize_frst(ft, (ft->fmt)[ft->i])))
		{
			ft_search_deafault(ft);
			return ;
		}
	}
	ft->value = (t_value *)malloc(sizeof(t_value));
	ft->ldbl = (t_ldbl *)malloc(sizeof(t_ldbl));
	ft_format(ft);
	ft_search_deafault(ft);
}
