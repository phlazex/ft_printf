/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfahey <mfahey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 18:30:15 by mfahey            #+#    #+#             */
/*   Updated: 2019/09/30 16:47:21 by mfahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_format_x_thrd(t_printf *ft)
{
	if (ft->z)
	{
		if (!(ft->precision) && ft->prec)
		{
			if (ft->width >= ft->length)
				ft_insert_chr(ft, 0, ft->width, ' ');
		}
		else
		{
			ft_insert_sharp(ft);
			ft_format_s(ft);
			if (ft->width > ft->length)
				ft_insert_chr(ft, 0, ft->width - ft->length, ' ');
		}
	}
	else
	{
		ft_insert_sharp(ft);
		ft_format_s(ft);
		if ((ft->width - ft->pn) > ft->length)
			ft_insert_chr(ft, 0, ft->width - ft->pn - ft->length, ' ');
	}
}

void	ft_format_x_scnd(t_printf *ft)
{
	if (ft->precision >= ft->length)
	{
		ft_insert_sharp(ft);
		ft_insert_chr(ft, 0, ft->precision - ft->length, '0');
		ft_format_s(ft);
		if ((ft->width - ft->pn) > ft->precision)
			ft_insert_chr(ft, 0, ft->width - ft->pn - ft->precision, ' ');
	}
	else
		ft_format_x_thrd(ft);
}

void	ft_format_x_frst(t_printf *ft)
{
	if (ft->flag->sharp && !(ft->z))
		ft->pn = 2;
	if (ft->width >= ft_max(ft->precision, ft->length))
	{
		if (ft->flag->minus)
			ft_format_x_scnd(ft);
		else
			ft_format_x_frth(ft);
	}
	else if (ft->precision >= ft->length)
	{
		ft_insert_sharp(ft);
		ft_insert_chr(ft, 0, ft->precision - ft->length, '0');
		ft_format_s(ft);
	}
	else
	{
		if (!(!(ft->precision) && ft->prec && ft->z))
		{
			ft_insert_sharp(ft);
			ft_format_s(ft);
		}
	}
}
