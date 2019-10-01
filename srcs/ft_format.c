/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfahey <mfahey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 15:58:20 by mfahey            #+#    #+#             */
/*   Updated: 2019/09/29 20:49:52 by mfahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_format(t_printf *ft)
{
	if (ft->percent)
	{
		ft->value->c = '%';
		ft_format_c(ft);
	}
	else if ((ft->type >= d) && (ft->type <= i))
		ft_format_di(ft);
	else if ((ft->type >= o) && (ft->type <= X))
		ft_format_oux(ft);
	else if ((ft->type >= f) && (ft->type <= A))
		ft_format_fega(ft);
	else if ((ft->type >= c) && (ft->type <= p))
		ft_format_csp(ft);
	else if (ft->type == n)
		ft_format_n(ft);
	free(ft->value);
	ft->value = NULL;
	free(ft->ldbl);
	ft->ldbl = NULL;
	ft_strdel(&(ft->ss));
}
