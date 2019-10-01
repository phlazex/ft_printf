/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfahey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 11:53:23 by mfahey            #+#    #+#             */
/*   Updated: 2018/12/01 12:06:42 by mfahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while ((s1[i] != '\0') && (s2[i] != '\0'))
		if ((unsigned char)s1[i] == (unsigned char)s2[i])
			i++;
		else
			break ;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
