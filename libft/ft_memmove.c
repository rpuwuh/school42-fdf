/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoetess <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 18:44:42 by bpoetess          #+#    #+#             */
/*   Updated: 2021/10/23 17:29:17 by bpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	i = 0;
	if (!dst && !src)
		return (0);
	if (dst <= src)
		ft_memcpy(dst, src, len);
	else
	{
		while (i < len)
		{
			*((char *)dst + len - i - 1) = *((char *)src + len - i - 1);
			i++;
		}
	}
	return (dst);
}
