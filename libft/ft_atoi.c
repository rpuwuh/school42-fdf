/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoetess <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 00:25:23 by bpoetess          #+#    #+#             */
/*   Updated: 2021/10/25 18:51:00 by bpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_readnums(const char *str, char sign)
{
	size_t		i;
	long int	res;

	i = 0;
	res = 0;
	if (ft_isdigit(str[i]))
	{
		while (ft_isdigit(str[i]))
		{
			res = res * 10 + str[i] - '0';
			i++;
			if (res * sign > 2147483647)
				return (-1);
			if (res * sign < -2147483648)
				return (0);
		}
	}
	else
		return (0);
	return ((int)(res * sign));
}

int	ft_atoi(const char *str)
{
	size_t	i;
	int		res;
	char	sign;

	i = 0;
	res = 0;
	sign = 1;
	while (str[i] == ' ' || (str [i] >= 9 && str [i] <= 13))
		i++;
	if (str[i] == '-' || str [i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	res = ft_readnums(str + i, sign);
	return (res);
}
