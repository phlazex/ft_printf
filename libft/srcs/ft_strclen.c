/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfahey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 17:26:41 by mfahey            #+#    #+#             */
/*   Updated: 2019/06/03 17:27:00 by mfahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strclen(const char *str, int c)
{
	size_t	i;

	i = 0;
	while ((str[i] != '\0') && (str[i] != (unsigned char)c))
		i++;
	return (i);
}
