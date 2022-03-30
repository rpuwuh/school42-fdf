/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoetess <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 20:15:28 by bpoetess          #+#    #+#             */
/*   Updated: 2021/10/25 15:54:10 by bpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	i = ft_strlen(s);
	if (c == 0)
		return ((char *)(s + i));
	while (i)
	{
		if (s [i] == (unsigned char) c)
			return ((char *)(s + i));
		i--;
	}
	if (*s == (unsigned char) c)
		return ((char *)s);
	return (0);
}
