/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_di_frst.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfahey <mfahey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 22:00:38 by mfahey            #+#    #+#             */
/*   Updated: 2019/09/29 21:44:56 by mfahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_format_di_sxth(t_printf *ft)
{
	if (!(ft->precision) && ft->prec)
	{
		ft_insert_chr(ft, 0, ft->width - ft->length - (ft->pn || ft->flag->plus
				|| ft->flag->space) + ft->z, ' ');
		ft_insert_di(ft);
		if (!(ft->z))
			ft_format_s(ft);
	}
	else
	{
		if (ft->flag->zero)
			ft_format_di_svnth(ft);
		else
		{
			ft_insert_chr(ft, 0, ft->width - ft->length - (ft->pn ||
					ft->flag->plus || ft->flag->space), ' ');
			ft_insert_di(ft);
		}
		ft_format_s(ft);
	}
}

void	ft_format_di_ffth(t_printf *ft)
{
	if (ft->precision >= ft->length)
	{
		ft_insert_chr(ft, 0, ft->width - ft->precision -
				(ft->flag->plus || ft->flag->space || ft->pn), ' ');
		ft_insert_di(ft);
		ft_insert_chr(ft, 0, ft->precision - ft->length, '0');
		ft_format_s(ft);
	}
	else
	{
		if (ft->flag->plus || ft->flag->zero || ft->flag->space)
			ft_format_di_sxth(ft);
		else
			ft_format_di_ghth(ft);
	}
}

void	ft_format_di_frth(t_printf *ft)
{
	if (ft->precision >= ft->length)
	{
		ft_insert_di(ft);
		ft_insert_chr(ft, 0, ft->precision - ft->length, '0');
		ft_format_s(ft);
		ft_insert_chr(ft, 0, ft->width - ft->precision -
				(ft->flag->plus || ft->flag->space || ft->pn), ' ');
	}
	else
	{
		ft_insert_di(ft);
		if (!(!(ft->precision) && ft->prec && ft->z))
			ft_format_s(ft);
		if (!(ft->precision) && ft->prec)
			ft_insert_chr(ft, 0, ft->width - ft->length - (ft->flag->plus
					|| ft->flag->space || ft->pn) + ft->z, ' ');
		else
			ft_insert_chr(ft, 0, ft->width - ft->length -
					(ft->flag->plus || ft->flag->space || ft->pn), ' ');
	}
}

void	ft_format_di_thrd(t_printf *ft)
{
	if (ft->width > ft_max(ft->precision, ft->length))
	{
		if (ft->flag->minus)
			ft_format_di_frth(ft);
		else
			ft_format_di_ffth(ft);
	}
	else if (ft->precision >= ft->length)
	{
		ft_insert_di(ft);
		ft_insert_chr(ft, 0, ft->precision - ft->length, '0');
		ft_format_s(ft);
	}
	else
		ft_format_di_nnth(ft);
}
