/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoetess <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 04:14:25 by bpoetess          #+#    #+#             */
/*   Updated: 2021/10/23 17:08:20 by bpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	ft_coincidence(char const	s, char const *set)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(set))
	{
		if (s == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	end;
	size_t	start;

	start = 0;
	end = ft_strlen(s1) - 1;
	while (s1[start] && ft_coincidence(s1[start], set))
		start++;
	while (end > start && ft_coincidence(s1[end], set))
		end--;
	return (ft_substr(s1, start, end - start + 1));
}
