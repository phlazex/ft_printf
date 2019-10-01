/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfahey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 17:05:59 by mfahey            #+#    #+#             */
/*   Updated: 2018/12/11 17:15:32 by mfahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*nxt;

	if (alst)
	{
		while (*alst)
		{
			nxt = (*alst)->next;
			del((*alst)->content, (*alst)->content_size);
			free(*alst);
			*alst = nxt;
		}
	}
}
