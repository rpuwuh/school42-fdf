/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoetess <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 23:20:24 by bpoetess          #+#    #+#             */
/*   Updated: 2021/10/25 19:42:47 by bpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{	
	size_t	i;

	if (*needle == '\0' || needle == haystack)
		return ((char *)haystack);
	if (ft_strlen(haystack) < len)
		len = ft_strlen(haystack);
	i = 0;
	while (ft_strlen(needle) <= len - i && *(haystack + i))
	{
		if (!ft_strncmp((haystack + i), needle, ft_strlen(needle)))
			return ((char *) haystack + i);
		i++;
	}
	return (0);
}
