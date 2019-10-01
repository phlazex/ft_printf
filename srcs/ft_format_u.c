/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfahey <mfahey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 18:30:26 by mfahey            #+#    #+#             */
/*   Updated: 2019/09/30 16:58:05 by mfahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_format_u_ffth(t_printf *ft)
{
	if (!(ft->precision) && ft->prec)
		ft_insert_chr(ft, 0, ft->width - ft->length +
				ft->z, ' ');
	else
	{
		if (ft->flag->zero && !(ft->prec))
			ft_insert_chr(ft, 0, ft->width - ft->length, '0');
		else
			ft_insert_chr(ft, 0, ft->width - ft->length, ' ');
		ft_format_s(ft);
	}
}

void	ft_format_u_frth(t_printf *ft)
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
			ft_format_u_ffth(ft);
		else
		{
			if (ft->prec)
				ft_insert_chr(ft, 0, ft->width - ft->length, ' ');
			else
			{
				if (ft->flag->zero)
					ft_insert_chr(ft, 0, ft->width - ft->length, '0');
				else
					ft_insert_chr(ft, 0, ft->width - ft->length, ' ');
			}
			ft_format_s(ft);
		}
	}
}

void	ft_format_u_thrd(t_printf *ft)
{
	if (ft->z)
	{
		if (!(ft->precision) && ft->prec)
		{
			ft_insert_chr(ft, 0, ft->width - ft->length +
					ft->z, ' ');
		}
		else
		{
			ft_format_s(ft);
			ft_insert_chr(ft, 0, ft->width - ft->length, ' ');
		}
	}
	else
	{
		ft_format_s(ft);
		ft_insert_chr(ft, 0, ft->width - ft->length, ' ');
	}
}

void	ft_format_u_scnd(t_printf *ft)
{
	if (ft->precision > ft->length)
	{
		ft_insert_chr(ft, 0, ft->precision - ft->length, '0');
		ft_format_s(ft);
		ft_insert_chr(ft, 0, ft->width - ft->precision, ' ');
	}
	else
		ft_format_u_thrd(ft);
}

void	ft_format_u_frst(t_printf *ft)
{
	if (ft->width >= ft_max(ft->precision, ft->length))
	{
		if (ft->flag->minus)
			ft_format_u_scnd(ft);
		else
			ft_format_u_frth(ft);
	}
	else if (ft->precision > ft->length)
	{
		ft_insert_chr(ft, 0, ft->precision - ft->length, '0');
		ft_format_s(ft);
	}
	else
	{
		if (ft->z)
		{
			if (!(ft->prec && !(ft->precision)))
				ft_format_s(ft);
		}
		else
			ft_format_s(ft);
	}
}
