/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfahey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 18:11:35 by mfahey            #+#    #+#             */
/*   Updated: 2018/12/11 18:53:24 by mfahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_dellst(t_list *lst)
{
	t_list *nxt;

	while (lst)
	{
		nxt = lst->next;
		free(lst);
		lst = nxt;
	}
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*nxt;
	t_list	*prv;

	nxt = NULL;
	if (lst)
	{
		nxt = f(lst);
		prv = nxt;
		lst = lst->next;
		while (lst)
		{
			if (!(prv->next = f(lst)))
			{
				ft_dellst(nxt);
				return (NULL);
			}
			prv = prv->next;
			lst = lst->next;
		}
	}
	return (nxt);
}
