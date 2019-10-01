/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfahey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 16:31:09 by mfahey            #+#    #+#             */
/*   Updated: 2018/12/05 17:11:51 by mfahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	size_t	i;

	if (!s1 || !s2)
		return (0);
	i = 0;
	while ((s1[i] != '\0') || (s2[i] != '\0'))
		if ((unsigned char)s1[i] == (unsigned char)s2[i])
			i++;
		else
			break ;
	if ((unsigned char)s1[i] - (unsigned char)s2[i] == 0)
		return (1);
	else
		return (0);
}
