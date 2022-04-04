/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoetess <bpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 01:13:08 by bpoetess          #+#    #+#             */
/*   Updated: 2022/04/04 21:20:56 by bpoetess         ###   ########.fr       */
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
			ft_putstr_fd(",", 1);
			ft_putnbr_fd(glb->mtx[i][j++], 1);
			ft_putstr_fd(" ", 1);
		}
		ft_putstr_fd("\n", 1);
		i++;
	}
}

void	fdf_draw(t_glb *glb)
{
	int	x;
	int	y;

	if (!glb)
		return ;
	x = 0;
	while (x < glb->x)
	{
		y = 0;
		while (y < glb->y)
		{
			glb->buf[0] = x;
			glb->buf[1] = y;
			glb->buf[2] = (x + 1);
			glb->buf[3] = (y);
			glb->buf[4] = 0xff0000;
			glb->buf[5] = 0xffffff;
			fdf_bresenham(glb);
			glb->buf[0] = x;
			glb->buf[1] = y;
			glb->buf[2] = (x);
			glb->buf[3] = (y + 1);
			glb->buf[4] = 0xff0000;
			glb->buf[5] = 0xffffff;
			fdf_bresenham(glb);
			y++;
		}
		x++;
		ft_putnbr_fd(x, 1);
		ft_putstr_fd("\t", 1);
	}
}

int	main(int argc, char **argv)
{
	t_glb	*glb;

	glb = fdf_initializemtx(argc, argv);
	fdf_putmtx(glb);
	fdf_initializemlx(glb);
	fdf_draw(glb);
	// glb->buf[0] = 10;
	// glb->buf[1] = 10;
	// glb->buf[2] = FDF_WIDTH;
	// glb->buf[3] = FDF_HEIGHT;
	// glb->buf[4] = 0x000000;
	// glb->buf[5] = 0xffffff;
	// fdf_bresenham(glb);
	mlx_put_image_to_window(glb->mlx_ptr, glb->win_ptr, glb->img_ptr, 0, 0);
	mlx_loop(glb->mlx_ptr);
}
