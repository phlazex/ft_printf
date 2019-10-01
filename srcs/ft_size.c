/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfahey <mfahey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 18:05:49 by mfahey            #+#    #+#             */
/*   Updated: 2019/08/07 15:49:44 by mfahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_issize_frth(t_printf *ft)
{
	if ((ft->fmt)[ft->i] == 'h')
	{
		(ft->i)++;
		if ((ft->fmt)[ft->i] == 'h')
		{
			(ft->i)++;
			ft->size = ft->size < hh ? hh : ft->size;
		}
		else
			ft->size = ft->size < h ? h : ft->size;
	}
	else
	{
		(ft->i)++;
		ft->size = ws;
	}
}

void	ft_issize_thrd(t_printf *ft)
{
	if ((ft->fmt)[ft->i] == 'l')
	{
		(ft->i)++;
		if ((ft->fmt)[ft->i] == 'l')
		{
			(ft->i)++;
			ft->size = ft->size < ll ? ll : ft->size;
		}
		else
			ft->size = ft->size < l ? l : ft->size;
	}
	else
		ft_issize_frth(ft);
}

void	ft_issize_scnd(t_printf *ft)
{
	if ((ft->fmt)[ft->i] == 'j')
	{
		(ft->i)++;
		ft->size = ft->size < j ? j : ft->size;
	}
	else if ((ft->fmt)[ft->i] == 'z')
	{
		(ft->i)++;
		ft->size = ft->size < z ? z : ft->size;
	}
	else if ((ft->fmt)[ft->i] == 'L')
	{
		(ft->i)++;
		ft->size = ft->size < L ? L : ft->size;
	}
	else
		ft_issize_thrd(ft);
}

int		ft_issize_frst(t_printf *ft, int c)
{
	size_t	i;

	i = 0;
	while ((ft->asize)[i] != '\0')
	{
		if ((ft->asize)[i] == (unsigned char)c)
			return (1);
		i++;
	}
	return (0);
}

void	ft_issize(t_printf *ft)
{
	while (((ft->fmt)[ft->i] != '\0') &&
			(ft_issize_frst(ft, (ft->fmt)[ft->i])))
		ft_issize_scnd(ft);
}
