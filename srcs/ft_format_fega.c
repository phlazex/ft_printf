/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_fega.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfahey <mfahey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 15:59:11 by mfahey            #+#    #+#             */
/*   Updated: 2019/09/30 17:46:52 by mfahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_nan_inf(t_printf *ft)
{
	if ((1.0 / Z) == ft->ldbl->lf)
		ft->ss = ft_strdup("inf");
	else if ((-1.0 / Z) == ft->ldbl->lf)
		ft->ss = ft_strdup("-inf");
	else if (ft->ldbl->lf != ft->ldbl->lf)
		ft->ss = ft_strdup("nan");
	else
		return (0);
	ft->length = ft_strlen(ft->ss);
	return (1);
}

void	ft_uniontomatrix_scnd(t_printf *ft)
{
	size_t	i;

	i = 16;
	while ((i < BFS) && (ft->exp >= Z))
	{
		ft->lpf += (long double)((ft->bf)[i]) *
				(long double)ft_pow(2, ft->exp);
		(ft->exp)--;
		i++;
	}
	while (i < BFS)
	{
		ft->rpf += (long double)((ft->bf)[i]) *
				(long double)ft_pow(2, ft->exp);
		(ft->exp)--;
		i++;
	}
}

void	ft_uniontomatrix_frst(t_printf *ft, size_t i, size_t o, char *value)
{
	size_t	j;

	j = 0;
	while (i < o)
	{
		(ft->bf)[i] = (value[j] == '1') ? 1 : 0;
		i++;
		j++;
	}
}

void	ft_uniontomatrix(t_printf *ft)
{
	size_t	i;
	size_t	length;
	char	*value;

	i = 0;
	while (i < BFS)
	{
		(ft->bf)[i] = 0;
		i++;
	}
	ft_uniontomatrix_frst(ft, 0, 1,
			value = ft_ulltoa_base(ft->ldbl->s_lfprt.sgn, 2));
	ft_strdel(&value);
	ft->pn = (ft->bf)[0];
	value = ft_ulltoa_base(ft->ldbl->s_lfprt.exp, 2);
	length = ft_strlen(value);
	ft_uniontomatrix_frst(ft, 1 + (ELF - length), 16, value);
	ft_strdel(&value);
	ft->exp = (long double)(ft->ldbl->s_lfprt.exp - P);
	value = ft_ulltoa_base(ft->ldbl->s_lfprt.mnt, 2);
	length = ft_strlen(value);
	ft_uniontomatrix_frst(ft, 16 + (MLF - length), BFS, value);
	ft_strdel(&value);
	ft_uniontomatrix_scnd(ft);
}

void	ft_format_fega(t_printf *ft)
{
	if (ft->size == L)
		ft->value->lf = va_arg(ft->ap, long double);
	else
		ft->value->lf = (long double)va_arg(ft->ap, double);
	ft->z = (ft->value->lf == Z) ? 1 : 0;
	ft->ldbl->lf = ft->value->lf;
	ft_uniontomatrix(ft);
	if (ft_nan_inf(ft))
		ft_format_fega_frst(ft);
	else
	{
		if (!(ft->prec))
			ft->precision = 6;
		ft_atof_printf(ft);
		if (ft->width > ft->length)
			ft_format_fega_frth(ft);
		else
		{
			if (ft->pn)
				ft_insert_chr(ft, 0, 1, '-');
			else
				ft_insert_f(ft);
			ft_format_s(ft);
		}
	}
}
