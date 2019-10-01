/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_o.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfahey <mfahey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 18:30:33 by mfahey            #+#    #+#             */
/*   Updated: 2019/09/30 17:08:56 by mfahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_format_o_thrd(t_printf *ft)
{
	if (ft->precision > ft->length)
	{
		ft_insert_chr(ft, 0, ft->width - ft->precision, ' ');
		ft_insert_chr(ft, 0, ft->precision - ft->length, '0');
		ft_format_s(ft);
	}
	else
	{
		if (ft->z)
			ft_format_o_frth(ft);
		else
			ft_format_o_ffth(ft);
	}
}

void	ft_format_o_scnd(t_printf *ft)
{
	if (ft->z)
	{
		if (ft->prec && !(ft->precision))
		{
			if (ft->flag->sharp)
				ft_format_s(ft);
			ft_insert_chr(ft, 0, ft->width -
					!(ft_bool(ft->flag->sharp)), ' ');
		}
		else
		{
			ft_format_s(ft);
			ft_insert_chr(ft, 0, ft->width - ft->length, ' ');
		}
	}
	else
	{
		if (ft->flag->sharp)
			ft_insert_chr(ft, 0, 1, '0');
		ft_format_s(ft);
		if (ft->width > ft->length)
			ft_insert_chr(ft, 0, ft->width - ft->length -
					!(ft_bool(ft->flag->sharp)), ' ');
	}
}

void	ft_format_o_frst(t_printf *ft)
{
	if (ft->width >= ft_max(ft->precision, ft->length))
	{
		if (ft->flag->minus)
		{
			if (ft->precision > ft->length)
			{
				ft_insert_chr(ft, 0, ft->precision - ft->length, '0');
				ft_format_s(ft);
				ft_insert_chr(ft, 0, ft->width - ft->precision, ' ');
			}
			else
				ft_format_o_scnd(ft);
		}
		else
			ft_format_o_thrd(ft);
	}
	else if (ft->precision > ft->length)
	{
		ft_insert_chr(ft, 0, ft->precision - ft->length, '0');
		ft_format_s(ft);
	}
	else
		ft_format_o_sxth(ft);
}
