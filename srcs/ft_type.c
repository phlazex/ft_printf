/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfahey <mfahey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 18:06:03 by mfahey            #+#    #+#             */
/*   Updated: 2019/08/14 19:25:34 by mfahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_istype_scnd(t_printf *ft, int c)
{
	if ((unsigned char)c == '%')
		(ft->percent)++;
	else
		ft->type = ft_istype_frst(ft, c);
	(ft->i)++;
}

int		ft_istype_frst(t_printf *ft, int c)
{
	size_t	i;

	if ((unsigned char)c == '%')
		return (22);
	i = 0;
	while ((ft->atype)[i] != '\0')
	{
		if ((ft->atype)[i] == (unsigned char)c)
			return (i + 1);
		i++;
	}
	return (0);
}

void	ft_istype(t_printf *ft)
{
	if (ft_istype_frst(ft, (ft->fmt)[ft->i]))
		ft_istype_scnd(ft, (ft->fmt)[ft->i]);
}
