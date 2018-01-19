/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivelutin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 19:32:36 by ivelutin          #+#    #+#             */
/*   Updated: 2017/01/16 19:32:37 by ivelutin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *list;
	t_list *prev;

	if (*alst)
	{
		list = *alst;
		while (list)
		{
			prev = list;
			list = list->next;
			del(prev->content, prev->content_size);
			free(prev);
		}
	}
	*alst = NULL;
}
