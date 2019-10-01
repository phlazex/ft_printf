/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_fega_frst.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfahey <mfahey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 17:36:52 by mfahey            #+#    #+#             */
/*   Updated: 2019/09/30 17:50:15 by mfahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_format_fega_ffth(t_printf *ft)
{
	if (ft->flag->zero)
	{
		if (ft->pn)
			ft_insert_chr(ft, 0, 1, '-');
		else
			ft_insert_f(ft);
		ft_insert_chr(ft, 0, ft->width - ft->length -
				(ft->flag->plus || ft->flag->space || ft->pn), '0');
		ft_format_s(ft);
	}
	else
	{
		ft_insert_chr(ft, 0, ft->width - ft->length -
				(ft->flag->plus || ft->flag->space || ft->pn), ' ');
		if (ft->pn)
			ft_insert_chr(ft, 0, 1, '-');
		else
			ft_insert_f(ft);
		ft_format_s(ft);
	}
}

void	ft_format_fega_frth(t_printf *ft)
{
	if (ft->flag->minus)
	{
		if (ft->pn)
			ft_insert_chr(ft, 0, 1, '-');
		else
			ft_insert_f(ft);
		ft_format_s(ft);
		ft_insert_chr(ft, 0, ft->width - ft->length -
				(ft->flag->plus || ft->flag->space || ft->pn), ' ');
	}
	else
		ft_format_fega_ffth(ft);
}

void	ft_format_fega_thrd(t_printf *ft)
{
	if (((-1.0 / Z) == ft->ldbl->lf) || (ft->ldbl->lf != ft->ldbl->lf))
	{
		ft_insert_chr(ft, 0, ft->width - ft->length, ' ');
		ft_format_s(ft);
	}
	else
	{
		ft_insert_chr(ft, 0, ft->width - ft->length -
				(ft->flag->plus || ft->flag->space), ' ');
		ft_insert_f(ft);
		ft_format_s(ft);
	}
}

void	ft_format_fega_scnd(t_printf *ft)
{
	if ((-1.0 / Z) == ft->ldbl->lf)
	{
		ft_format_s(ft);
		ft_insert_chr(ft, 0, ft->width - ft->length -
				(ft->flag->plus && !(ft->pn)), ' ');
	}
	else if (ft->ldbl->lf != ft->ldbl->lf)
	{
		ft_format_s(ft);
		ft_insert_chr(ft, 0, ft->width - ft->length, ' ');
	}
	else
	{
		ft_insert_f(ft);
		ft_format_s(ft);
		ft_insert_chr(ft, 0, ft->width - ft->length -
				(ft->flag->plus || ft->flag->space), ' ');
	}
}

void	ft_format_fega_frst(t_printf *ft)
{
	if (ft->width > ft->length)
	{
		if (ft->flag->minus)
			ft_format_fega_scnd(ft);
		else
			ft_format_fega_thrd(ft);
	}
	else
	{
		if (((-1.0 / Z) == ft->ldbl->lf) || (ft->ldbl->lf != ft->ldbl->lf))
			ft_format_s(ft);
		else
		{
			ft_insert_f(ft);
			ft_format_s(ft);
		}
	}
}
