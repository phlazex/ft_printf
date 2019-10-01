/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_di.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfahey <mfahey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 15:58:55 by mfahey            #+#    #+#             */
/*   Updated: 2019/09/29 21:11:04 by mfahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_format_di_scnd(t_printf *ft)
{
	if (ft->size == ws)
	{
		ft->value->di = va_arg(ft->ap, int);
		ft->pn = (ft->value->di < 0) ? 1 : 0;
		ft->z = (ft->value->di == 0) ? 1 : 0;
		ft->ss = ft_llitoa_base(ft->value->di, 10);
	}
	else if (ft->size == z)
	{
		ft->value->z = va_arg(ft->ap, size_t);
		ft->z = (ft->value->z == 0) ? 1 : 0;
		ft->ss = ft_ulltoa_base(ft->value->z, 10);
	}
}

void	ft_format_di_frst(t_printf *ft)
{
	if (ft->size == hh)
	{
		ft->value->hhdi = (signed char)va_arg(ft->ap, int);
		ft->pn = (ft->value->hhdi < 0) ? 1 : 0;
		ft->z = (ft->value->hhdi == 0) ? 1 : 0;
		ft->ss = ft_llitoa_base(ft->value->hhdi, 10);
	}
	else if (ft->size == h)
	{
		ft->value->hdi = (short int)va_arg(ft->ap, int);
		ft->pn = (ft->value->hdi < 0) ? 1 : 0;
		ft->z = (ft->value->hdi == 0) ? 1 : 0;
		ft->ss = ft_llitoa_base(ft->value->hdi, 10);
	}
	else
		ft_format_di_scnd(ft);
}

void	ft_format_di(t_printf *ft)
{
	if ((ft->type == D) || (ft->size == l))
	{
		ft->value->ldi = va_arg(ft->ap, long int);
		ft->pn = (ft->value->ldi < 0) ? 1 : 0;
		ft->z = (ft->value->ldi == 0) ? 1 : 0;
		ft->ss = ft_llitoa_base(ft->value->ldi, 10);
	}
	else if ((ft->size == ll) || (ft->size == j))
	{
		ft->value->lldi = va_arg(ft->ap, long long int);
		ft->pn = (ft->value->lldi < 0) ? 1 : 0;
		ft->z = (ft->value->lldi == 0) ? 1 : 0;
		ft->ss = ft_llitoa_base(ft->value->lldi, 10);
	}
	else
		ft_format_di_frst(ft);
	if (ft->pn)
		(ft->k)++;
	ft->length = ft_strlen(ft->ss) - ft->pn;
	ft_format_di_thrd(ft);
}
