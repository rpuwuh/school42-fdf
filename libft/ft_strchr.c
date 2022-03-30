/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoetess <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 19:52:45 by bpoetess          #+#    #+#             */
/*   Updated: 2021/10/25 15:36:19 by bpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s [i])
	{
		if (s[i] == (unsigned char) c)
			return ((char *)(s + i));
		i++;
	}
	if (s[i] == (unsigned char) c)
		return ((char *)(s + i));
	return (0);
}
