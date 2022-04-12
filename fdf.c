/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoetess <bpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 01:13:08 by bpoetess          #+#    #+#             */
/*   Updated: 2022/04/12 20:43:09 by bpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_putmtx(t_glb *glb)
{
	int	i;
	int	j;

	ft_putnbr_fd(glb->x, 1);
	ft_putstr_fd("\t", 1);
	ft_putnbr_fd(glb->y, 1);
	ft_putstr_fd("\n", 1);
	i = 0;
	while (i < glb->y)
	{
		j = 0;
		while (j < glb->x)
		{
			ft_putnbr_fd(glb->mtx[i][j++], 1);
			j++;
			ft_putstr_fd(",", 1);
			ft_putnbr_fd(glb->mtx[i][j++], 1);
			ft_putstr_fd("\t", 1);
		}
		ft_putstr_fd("\n", 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_glb	*glb;

	glb = fdf_initializemtx(argc, argv);
	fdf_putmtx(glb);
	fdf_initializemlx(glb);
	fdf_draw(glb);
	mlx_key_hook(glb->win_ptr, fdf_hook, glb);
	mlx_loop(glb->mlx_ptr);
}
