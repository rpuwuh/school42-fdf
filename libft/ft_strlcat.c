/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoetess <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 07:30:40 by bpoetess          #+#    #+#             */
/*   Updated: 2021/10/13 12:23:07 by bpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_s;

	if (size)
	{
		dst_s = ft_strlen(dst);
		if (size > dst_s)
		{
			ft_strlcpy(dst + dst_s, src, size - dst_s);
			return (dst_s + ft_strlen(src));
		}
		else
			return (ft_strlen(src) + size);
	}
	else
		return (ft_strlen(src));
}
