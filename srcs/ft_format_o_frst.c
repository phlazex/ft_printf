/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_o_frst.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfahey <mfahey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 17:07:14 by mfahey            #+#    #+#             */
/*   Updated: 2019/09/30 17:08:44 by mfahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_format_o_sxth(t_printf *ft)
{
	if (ft->z)
	{
		if (ft->prec)
		{
			if ((ft->flag->sharp && !(ft->precision)) || ft->precision)
				ft_format_s(ft);
		}
		else
			ft_format_s(ft);
	}
	else
	{
		if (ft->flag->sharp)
			ft_insert_chr(ft, 0, 1, '0');
		ft_format_s(ft);
	}
}

void	ft_format_o_ffth(t_printf *ft)
{
	if (!(ft->prec))
	{
		if (ft->width > ft->length)
		{
			if (ft->flag->zero)
				ft_insert_chr(ft, 0, ft->width - ft->length -
						!(ft_bool(ft->flag->sharp)), '0');
			else
				ft_insert_chr(ft, 0, ft->width - ft->length -
						!(ft_bool(ft->flag->sharp)), ' ');
		}
		if (ft->flag->sharp)
			ft_insert_chr(ft, 0, 1, '0');
		ft_format_s(ft);
	}
	else
	{
		if (ft->width > ft->length)
			ft_insert_chr(ft, 0, ft->width - ft->length -
					!(ft_bool(ft->flag->sharp)), ' ');
		if (ft->flag->sharp)
			ft_insert_chr(ft, 0, 1, '0');
		ft_format_s(ft);
	}
}

void	ft_format_o_frth(t_printf *ft)
{
	if (!(ft->prec))
	{
		if (ft->flag->zero)
			ft_insert_chr(ft, 0, ft->width - ft->length, '0');
		else
			ft_insert_chr(ft, 0, ft->width - ft->length, ' ');
		ft_format_s(ft);
	}
	else if (ft->prec && !(ft->precision))
	{
		ft_insert_chr(ft, 0, ft->width -
				!(ft_bool(ft->flag->sharp)), ' ');
		if (ft->flag->sharp)
			ft_format_s(ft);
	}
	else
	{
		ft_insert_chr(ft, 0, ft->width - ft->length, ' ');
		ft_format_s(ft);
	}
}
