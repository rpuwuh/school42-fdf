/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoetess <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 15:35:50 by bpoetess          #+#    #+#             */
/*   Updated: 2021/10/21 15:29:52 by bpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*pointer;
	t_list	*prev;

	if (!del || lst == 0 || *lst == 0)
		return ;
	pointer = *lst;
	while (pointer->next)
	{
		prev = pointer;
		pointer = pointer->next;
		del(prev->content);
		free(prev);
	}
	del(pointer->content);
	free(pointer);
	*lst = 0;
}
