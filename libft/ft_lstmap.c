/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoetess <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 15:45:39 by bpoetess          #+#    #+#             */
/*   Updated: 2021/10/21 16:57:10 by bpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//static void

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;
	t_list	*lastlst;

	if (!lst || !f)
		return (0);
	res = ft_lstnew(f(lst->content));
	if (res == 0)
		return (0);
	lst = lst->next;
	lastlst = res;
	while (lst)
	{
		lastlst->next = ft_lstnew(f(lst->content));
		lastlst = lastlst->next;
		if (lastlst == 0)
		{
			ft_lstclear(&res, del);
			return (0);
		}
		lst = lst->next;
	}
	return (res);
}
