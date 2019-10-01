/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfahey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 12:16:23 by mfahey            #+#    #+#             */
/*   Updated: 2018/12/01 12:32:47 by mfahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] != '\0') && (s2[i] != '\0') && (i < n))
		if ((unsigned char)s1[i] == (unsigned char)s2[i])
			i++;
		else
			break ;
	if (i >= n)
		i = n - 1;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
