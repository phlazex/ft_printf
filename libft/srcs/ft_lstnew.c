/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfahey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 14:39:43 by mfahey            #+#    #+#             */
/*   Updated: 2018/12/11 16:10:35 by mfahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*lstn;

	if (!(lstn = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (content == NULL)
	{
		lstn->content = NULL;
		lstn->content_size = 0;
	}
	else
	{
		if (!(lstn->content = malloc(content_size)))
		{
			free(lstn);
			return (NULL);
		}
		lstn->content = ft_memcpy(lstn->content, content, content_size);
		lstn->content_size = content_size;
	}
	lstn->next = NULL;
	return (lstn);
}
