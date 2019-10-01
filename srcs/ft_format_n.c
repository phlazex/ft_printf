/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_n.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfahey <mfahey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 19:50:33 by mfahey            #+#    #+#             */
/*   Updated: 2019/09/29 21:12:57 by mfahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_format_n_frst(t_printf *ft)
{
	if (ft->size == h)
	{
		ft->value->hn = (short int *)va_arg(ft->ap, int *);
		*(ft->value->hn) = (short int)(ft->j);
	}
	else if (ft->size == ws)
	{
		ft->value->n = va_arg(ft->ap, int *);
		*(ft->value->n) = ft->j;
	}
	else if (ft->size == z)
	{
		ft->value->zn = va_arg(ft->ap, size_t *);
		*(ft->value->zn) = (size_t)ft->j;
	}
}

void	ft_format_n(t_printf *ft)
{
	if (ft->size == l)
	{
		ft->value->ln = va_arg(ft->ap, long int *);
		*(ft->value->ln) = (long int)(ft->j);
	}
	else if ((ft->size == ll) || (ft->size == j))
	{
		ft->value->lln = va_arg(ft->ap, long long int *);
		*(ft->value->lln) = (long long int)(ft->j);
	}
	else if (ft->size == hh)
	{
		ft->value->hhn = (signed char *)va_arg(ft->ap, int *);
		*(ft->value->hhn) = (signed char)(ft->j);
	}
	else
		ft_format_n_frst(ft);
}
