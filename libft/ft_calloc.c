/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoetess <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 02:48:58 by bpoetess          #+#    #+#             */
/*   Updated: 2021/10/13 10:20:28 by bpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*res;
	size_t	i;

	res = malloc (count * size);
	if (res == 0)
		return (0);
	i = 0;
	while (i < count * size)
	{
		*((char *) res + i) = '\0';
		i++;
	}
	return (res);
}
