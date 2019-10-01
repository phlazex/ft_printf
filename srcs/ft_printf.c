/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfahey <mfahey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 16:40:50 by mfahey            #+#    #+#             */
/*   Updated: 2019/09/30 17:51:16 by mfahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_free(t_printf *ft)
{
	ft->fmt = NULL;
	ft_strdel(&(ft->aflag));
	free(ft->flag);
	ft->flag = NULL;
	ft_strdel(&(ft->asize));
	ft_strdel(&(ft->atype));
	free(ft);
	ft = NULL;
}

t_printf	*ft_default(t_printf *ft, const char *format)
{
	ft = (t_printf *)malloc(sizeof(t_printf));
	ft->fmt = format;
	ft->ss = NULL;
	ft->i = 0;
	ft->j = 0;
	ft->aflag = ft_strdup("#0- +");
	ft->flag = (t_flag *)malloc(sizeof(t_flag));
	ft->asize = ft_strdup("hljztL");
	ft->atype = ft_strdup("dDioOuUxXfFeEgGaAcspn");
	ft_search_deafault(ft);
	return (ft);
}

int			ft_printf(const char *format, ...)
{
	t_printf	*ft;
	int			k;

	ft = ft_default(ft, format);
	va_start(ft->ap, format);
	while (format[ft->i] != '\0')
	{
		while ((format[ft->i] != '\0') && (format[ft->i] != '%'))
		{
			(ft->str)[ft->j] = format[ft->i];
			(ft->i)++;
			(ft->j)++;
		}
		if (format[ft->i] == '%')
		{
			(ft->i)++;
			ft_search(ft);
		}
	}
	va_end(ft->ap);
	(ft->str)[ft->j] = '\0';
	write(1, ft->str, ft->j);
	k = (int)(ft->j);
	ft_free(ft);
	return (k);
}
