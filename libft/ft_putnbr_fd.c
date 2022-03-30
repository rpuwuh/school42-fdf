/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoetess <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 05:45:33 by bpoetess          #+#    #+#             */
/*   Updated: 2021/10/13 05:46:18 by bpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n >= 0 && n <= 9)
		ft_putchar_fd(n + '0', fd);
	else if (n >= -9 && n <= -1)
	{
		ft_putchar_fd('-', fd);
		ft_putchar_fd((-n) + '0', fd);
	}
	else
	{
		if (n > 0)
		{
			ft_putnbr_fd(n / 10, fd);
			ft_putnbr_fd(n % 10, fd);
		}
		else
		{
			ft_putchar_fd('-', fd);
			ft_putnbr_fd(-(n / 10), fd);
			ft_putnbr_fd(-(n % 10), fd);
		}
	}
}
