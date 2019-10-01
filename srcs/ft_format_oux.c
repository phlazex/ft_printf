/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_oux.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfahey <mfahey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 15:59:28 by mfahey            #+#    #+#             */
/*   Updated: 2019/09/29 21:14:47 by mfahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_format_x(t_printf *ft)
{
	size_t	i;

	if (ft->size == l)
		ft->ss = ft_ulltoa_base(ft->value->loux, 16);
	else if ((ft->size == ll) || (ft->size == j))
		ft->ss = ft_ulltoa_base(ft->value->lloux, 16);
	else if (ft->size == hh)
		ft->ss = ft_ulltoa_base(ft->value->hhoux, 16);
	else if (ft->size == h)
		ft->ss = ft_ulltoa_base(ft->value->houx, 16);
	else if (ft->size == ws)
		ft->ss = ft_ulltoa_base(ft->value->oux, 16);
	else if (ft->size == z)
		ft->ss = ft_ulltoa_base(ft->value->z, 16);
	i = 0;
	if (ft->type == X)
		while ((ft->ss)[i] != '\0')
		{
			(ft->ss)[i] = ft_toupper((ft->ss)[i]);
			i++;
		}
	ft->length = ft_strlen(ft->ss);
	ft_format_x_frst(ft);
}

void	ft_format_u(t_printf *ft)
{
	if ((ft->type == U) || (ft->size == l))
		ft->ss = ft_ulltoa_base(ft->value->loux, 10);
	else if ((ft->size == ll) || (ft->size == j))
		ft->ss = ft_ulltoa_base(ft->value->lloux, 10);
	else if (ft->size == hh)
		ft->ss = ft_ulltoa_base(ft->value->hhoux, 10);
	else if (ft->size == h)
		ft->ss = ft_ulltoa_base(ft->value->houx, 10);
	else if (ft->size == ws)
		ft->ss = ft_ulltoa_base(ft->value->oux, 10);
	else if (ft->size == z)
		ft->ss = ft_ulltoa_base(ft->value->z, 10);
	ft->length = ft_strlen(ft->ss);
	ft_format_u_frst(ft);
}

void	ft_format_o(t_printf *ft)
{
	if ((ft->type == O) || (ft->size == l))
		ft->ss = ft_ulltoa_base(ft->value->loux, 8);
	else if ((ft->size == ll) || (ft->size == j))
		ft->ss = ft_ulltoa_base(ft->value->lloux, 8);
	else if (ft->size == hh)
		ft->ss = ft_ulltoa_base(ft->value->hhoux, 8);
	else if (ft->size == h)
		ft->ss = ft_ulltoa_base(ft->value->houx, 8);
	else if (ft->size == ws)
		ft->ss = ft_ulltoa_base(ft->value->oux, 8);
	else if (ft->size == z)
		ft->ss = ft_ulltoa_base(ft->value->z, 8);
	ft->length = ft_strlen(ft->ss);
	ft_format_o_frst(ft);
}

void	ft_format_oux_frst(t_printf *ft)
{
	if (ft->size == hh)
	{
		ft->value->hhoux = (unsigned char)va_arg(ft->ap, unsigned int);
		ft->z = (ft->value->hhoux == 0) ? 1 : 0;
	}
	else if (ft->size == h)
	{
		ft->value->houx = (unsigned short int)va_arg(ft->ap, unsigned int);
		ft->z = (ft->value->houx == 0) ? 1 : 0;
	}
	else if (ft->size == ws)
	{
		ft->value->oux = va_arg(ft->ap, unsigned int);
		ft->z = (ft->value->oux == 0) ? 1 : 0;
	}
	else if (ft->size == z)
	{
		ft->value->z = va_arg(ft->ap, size_t);
		ft->z = (ft->value->z == 0) ? 1 : 0;
	}
}

void	ft_format_oux(t_printf *ft)
{
	if ((ft->type == O) || (ft->type == U) || (ft->size == l))
	{
		ft->value->loux = va_arg(ft->ap, unsigned long int);
		ft->z = (ft->value->loux == 0) ? 1 : 0;
	}
	else if ((ft->size == ll) || (ft->size == j))
	{
		ft->value->lloux = va_arg(ft->ap, unsigned long long int);
		ft->z = (ft->value->lloux == 0) ? 1 : 0;
	}
	else
		ft_format_oux_frst(ft);
	if ((ft->type == o) || (ft->type == O))
		ft_format_o(ft);
	else if ((ft->type == u) || (ft->type == U))
		ft_format_u(ft);
	else if ((ft->type == x) || (ft->type == X))
		ft_format_x(ft);
}
