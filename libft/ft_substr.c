/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoetess <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 01:55:02 by bpoetess          #+#    #+#             */
/*   Updated: 2021/10/25 20:50:51 by bpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*res;

	if (start >= ft_strlen(s))
	{
		res = (char *) ft_calloc (1, 1);
		return (res);
	}
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	res = (char *) ft_calloc (len + 1, sizeof(char));
	if (res == 0)
		return (0);
	i = 0;
	while (i < len && s[start + i])
	{
		res[i] = s[start + i];
		i++;
	}
	ft_bzero(res + i, len - i + 1);
	return (res);
}
