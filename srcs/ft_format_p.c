/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfahey <mfahey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 18:48:26 by mfahey            #+#    #+#             */
/*   Updated: 2019/09/29 21:58:32 by mfahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_format_p_ffth(t_printf *ft)
{
	if (ft->flag->zero)
	{
		if (!(ft->prec))
		{
			ft_insert_sharp(ft);
			ft_insert_chr(ft, 0, ft->width - ft->length - ft->pn, '0');
		}
		else
		{
			ft_insert_chr(ft, 0, ft->width - ft->length - ft->pn, ' ');
			ft_insert_sharp(ft);
		}
		ft_format_s(ft);
	}
	else
	{
		ft_insert_chr(ft, 0, ft->width - ft->length - ft->pn, ' ');
		ft_insert_sharp(ft);
		ft_format_s(ft);
	}
}

void	ft_format_p_frth(t_printf *ft)
{
	if (ft->flag->zero)
	{
		if (!(ft->prec))
		{
			ft_insert_sharp(ft);
			ft_insert_chr(ft, 0, ft->width - ft->length - ft->pn, '0');
		}
		else
		{
			ft_insert_chr(ft, 0, ft->width - ft->pn, ' ');
			ft_insert_sharp(ft);
		}
		if (!(ft->prec && !(ft->precision)))
			ft_format_s(ft);
	}
	else
	{
		if (!(ft->prec))
			ft_insert_chr(ft, 0, ft->width - ft->length - ft->pn, ' ');
		else
			ft_insert_chr(ft, 0, ft->width - ft->pn, ' ');
		ft_insert_sharp(ft);
		if (!(ft->prec && !(ft->precision)))
			ft_format_s(ft);
	}
}

void	ft_format_p_thrd(t_printf *ft)
{
	if (ft->precision >= ft->length)
	{
		ft_insert_chr(ft, 0, ft->width - ft->precision - ft->pn, ' ');
		ft_insert_sharp(ft);
		ft_insert_chr(ft, 0, ft->precision - ft->length, '0');
		ft_format_s(ft);
	}
	else
	{
		if (ft->z)
			ft_format_p_frth(ft);
		else
			ft_format_p_ffth(ft);
	}
}

void	ft_format_p_scnd(t_printf *ft)
{
	ft_insert_sharp(ft);
	if (ft->precision >= ft->length)
	{
		ft_insert_chr(ft, 0, ft->precision - ft->length, '0');
		ft_format_s(ft);
		ft_insert_chr(ft, 0, ft->width - ft->precision - ft->pn, ' ');
	}
	else
	{
		if (ft->z)
		{
			if (!(ft->prec && !(ft->precision)))
				ft_format_s(ft);
			if (!(ft->prec))
				ft_insert_chr(ft, 0, ft->width - ft->length - ft->pn, ' ');
			else
				ft_insert_chr(ft, 0, ft->width - ft->pn, ' ');
		}
		else
		{
			ft_format_s(ft);
			ft_insert_chr(ft, 0, ft->width - ft->length - ft->pn, ' ');
		}
	}
}

void	ft_format_p_frst(t_printf *ft)
{
	if ((ft->width - ft->pn) >= ft_max(ft->precision, ft->length))
	{
		if (ft->flag->minus)
			ft_format_p_scnd(ft);
		else
			ft_format_p_thrd(ft);
	}
	else if (ft->precision >= ft->length)
	{
		ft_insert_sharp(ft);
		ft_insert_chr(ft, 0, ft->precision - ft->length, '0');
		ft_format_s(ft);
	}
	else
	{
		ft_insert_sharp(ft);
		if (ft->z)
		{
			if (!(ft->prec && !(ft->precision)))
				ft_format_s(ft);
		}
		else
			ft_format_s(ft);
	}
}
