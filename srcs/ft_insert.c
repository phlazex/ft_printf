/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfahey <mfahey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 19:38:53 by mfahey            #+#    #+#             */
/*   Updated: 2019/09/29 20:00:01 by mfahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_insert_f(t_printf *ft)
{
	if (ft->flag->plus)
		ft_insert_chr(ft, 0, 1, '+');
	else if (ft->flag->space)
		ft_insert_chr(ft, 0, 1, ' ');
}

void	ft_insert_sharp(t_printf *ft)
{
	if (ft->type == p)
	{
		ft_insert_chr(ft, 0, 1, '0');
		ft_insert_chr(ft, 0, 1, 'x');
	}
	else if (ft->flag->sharp && !(ft->z))
	{
		ft_insert_chr(ft, 0, 1, '0');
		if (ft->type == x)
			ft_insert_chr(ft, 0, 1, 'x');
		else
			ft_insert_chr(ft, 0, 1, 'X');
	}
}

void	ft_insert_di(t_printf *ft)
{
	if (ft->pn)
		ft_insert_chr(ft, 0, 1, '-');
	else if (ft->flag->plus && !(ft->pn))
		ft_insert_chr(ft, 0, 1, '+');
	else if (ft->flag->space && !(ft->pn))
		ft_insert_chr(ft, 0, 1, ' ');
}

void	ft_insert_chr(t_printf *ft, size_t i, size_t length, int chr)
{
	while (i < length)
	{
		(ft->str)[ft->j] = (unsigned char)chr;
		(ft->j)++;
		i++;
	}
}
