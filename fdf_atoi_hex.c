/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_atoi_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoetess <bpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 04:38:26 by bpoetess          #+#    #+#             */
/*   Updated: 2022/04/03 05:02:27 by bpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_readnums(const char *str, char sign)
{
	size_t		i;
	long int	res;

	i = 0;
	res = 0;
	if (ft_isdigit(str[i]) || (str[i] >= 'a' && str[i] <= 'f'))
	{
		while (ft_isdigit(str[i]) || (str[i] >= 'a' && str[i] <= 'f'))
		{
			if (ft_isdigit(str[i]))
				res = res * 16 + str[i] - '0';
			else
				res = res * 16 + 10 + str[i] - 'a';
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

int	fdf_atoi_hex(const char *str)
{
	size_t	i;
	int		res;
	char	sign;

	if (!str || !*str)
		return (0);
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
	while (str[i] == '0' || str [i] == 'x')
		i++;
	res = ft_readnums(str + i, sign);
	return (res);
}
