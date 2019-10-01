/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfahey <mfahey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 18:04:52 by mfahey            #+#    #+#             */
/*   Updated: 2019/07/31 22:27:19 by mfahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_isflag_scnd(t_printf *ft, int c)
{
	if ((unsigned char)c == '#')
		(ft->flag->sharp)++;
	else if ((unsigned char)c == '0')
		(ft->flag->zero)++;
	else if ((unsigned char)c == '-')
		(ft->flag->minus)++;
	else if ((unsigned char)c == ' ')
		(ft->flag->space)++;
	else if ((unsigned char)c == '+')
		(ft->flag->plus)++;
	(ft->i)++;
}

int		ft_isflag_frst(t_printf *ft, int c)
{
	size_t	i;

	i = 0;
	while ((ft->aflag)[i] != '\0')
	{
		if ((ft->aflag)[i] == (unsigned char)c)
			return (1);
		i++;
	}
	return (0);
}

void	ft_isflag(t_printf *ft)
{
	while (((ft->fmt)[ft->i] != '\0') &&
			(ft_isflag_frst(ft, (ft->fmt)[ft->i])))
		ft_isflag_scnd(ft, (ft->fmt)[ft->i]);
}
