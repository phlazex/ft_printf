/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_csp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfahey <mfahey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 15:58:39 by mfahey            #+#    #+#             */
/*   Updated: 2019/09/29 20:50:38 by mfahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_format_p(t_printf *ft)
{
	ft->value->z = va_arg(ft->ap, size_t);
	ft->z = (ft->value->z == 0) ? 1 : 0;
	ft->pn = 2;
	ft->ss = ft_ulltoa_base(ft->value->z, 16);
	ft->length = ft_strlen(ft->ss);
	ft_format_p_frst(ft);
}

void	ft_format_s(t_printf *ft)
{
	if (ft->type == s)
	{
		if (ft->prec)
			ft->length = ft_min(ft_strlen(ft->ss), ft->precision);
		else
			ft->length = ft_strlen(ft->ss);
		ft_format_s_frst(ft);
	}
	else
		while ((ft->ss)[ft->k] != '\0')
		{
			ft_insert_chr(ft, 0, 1, (ft->ss)[ft->k]);
			(ft->k)++;
		}
}

void	ft_format_c(t_printf *ft)
{
	int		chr;

	if (ft->flag->minus)
	{
		ft_insert_chr(ft, 0, 1, ft->value->c);
		ft_insert_chr(ft, 1, ft->width, ' ');
	}
	else
	{
		chr = ft->flag->zero ? '0' : ' ';
		ft_insert_chr(ft, 1, ft->width, chr);
		ft_insert_chr(ft, 0, 1, ft->value->c);
	}
}

void	ft_format_csp(t_printf *ft)
{
	if (ft->type == c)
	{
		ft->value->c = va_arg(ft->ap, int);
		ft_format_c(ft);
	}
	else if (ft->type == s)
	{
		if (!(ft->ss = ft_strdup(va_arg(ft->ap, char *))))
			ft->ss = ft_strdup("(null)");
		ft_format_s(ft);
	}
	else if (ft->type == p)
		ft_format_p(ft);
}
