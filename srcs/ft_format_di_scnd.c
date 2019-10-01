/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_di_scnd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfahey <mfahey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 21:43:35 by mfahey            #+#    #+#             */
/*   Updated: 2019/09/29 21:44:50 by mfahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_format_di_nnth(t_printf *ft)
{
	if (ft->z)
	{
		ft_insert_di(ft);
		if (ft->prec && !(ft->precision))
		{
			if (ft->width)
				ft_insert_chr(ft, 0, ft->width - (ft->flag->plus ||
						ft->flag->space), ' ');
		}
		else if (!(ft->prec))
			ft_format_s(ft);
		else
		{
			if (ft->width)
				ft_insert_chr(ft, 0, ft->width, ' ');
			ft_format_s(ft);
		}
	}
	else
	{
		ft_insert_di(ft);
		ft_format_s(ft);
	}
}

void	ft_format_di_ghth(t_printf *ft)
{
	if (!(ft->precision) && ft->prec)
	{
		ft_insert_chr(ft, 0, ft->width - ft->length - ft->pn + ft->z, ' ');
		ft_insert_di(ft);
		if (!(ft->z))
			ft_format_s(ft);
	}
	else
	{
		ft_insert_chr(ft, 0, ft->width - ft->length - ft->pn, ' ');
		ft_insert_di(ft);
		ft_format_s(ft);
	}
}

void	ft_format_di_svnth(t_printf *ft)
{
	if (ft->flag->plus || ft->flag->space)
	{
		if (ft->precision)
		{
			ft_insert_chr(ft, 0, ft->width - ft_max(ft->length, ft->precision)
					- (ft->pn || ft->flag->plus || ft->flag->space), ' ');
			ft_insert_di(ft);
		}
		else
		{
			ft_insert_di(ft);
			ft_insert_chr(ft, 0, ft->width - ft->length - (ft->pn ||
					ft->flag->plus || ft->flag->space), '0');
		}
	}
	else if (!(ft->precision))
	{
		ft_insert_di(ft);
		ft_insert_chr(ft, 0, ft->width - ft->length - ft->pn, '0');
	}
	else
	{
		ft_insert_chr(ft, 0, ft->width - ft->length - ft->pn, ' ');
		ft_insert_di(ft);
	}
}
