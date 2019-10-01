/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_x_frst.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfahey <mfahey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 16:39:14 by mfahey            #+#    #+#             */
/*   Updated: 2019/09/30 16:47:22 by mfahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_format_x_sxth(t_printf *ft)
{
	if (ft->flag->zero && !(ft->prec))
	{
		ft_insert_sharp(ft);
		if ((ft->width - ft->pn) > ft->length)
			ft_insert_chr(ft, 0, ft->width - ft->pn - ft->length, '0');
	}
	else
	{
		if ((ft->width - ft->pn) > ft->length)
			ft_insert_chr(ft, 0, ft->width - ft->pn - ft->length, ' ');
		ft_insert_sharp(ft);
	}
	ft_format_s(ft);
}

void	ft_format_x_ffth(t_printf *ft)
{
	if (!(ft->precision) && ft->prec)
	{
		if (ft->width >= ft->length)
			ft_insert_chr(ft, 0, ft->width, ' ');
	}
	else
	{
		if (ft->flag->zero)
		{
			if (ft->width > ft->length)
				ft_insert_chr(ft, 0, ft->width - ft->length, '0');
		}
		else
		{
			if (ft->width > ft->length)
				ft_insert_chr(ft, 0, ft->width - ft->length, ' ');
		}
		ft_insert_sharp(ft);
		ft_format_s(ft);
	}
}

void	ft_format_x_frth(t_printf *ft)
{
	if (ft->precision >= ft->length)
	{
		if ((ft->width - ft->pn) > ft->precision)
			ft_insert_chr(ft, 0, ft->width - ft->pn - ft->precision, ' ');
		ft_insert_sharp(ft);
		ft_insert_chr(ft, 0, ft->precision - ft->length, '0');
		ft_format_s(ft);
	}
	else
	{
		if (ft->z)
			ft_format_x_ffth(ft);
		else
			ft_format_x_sxth(ft);
	}
}
