/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoetess <bpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 01:13:08 by bpoetess          #+#    #+#             */
/*   Updated: 2022/04/06 15:45:21 by bpoetess         ###   ########.fr       */
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
			// ft_putstr_fd(",", 1);
			// ft_putnbr_fd(glb->mtx[i][j++], 1);
			ft_putstr_fd("\t", 1);
		}
		ft_putstr_fd("\n", 1);
		i++;
	}
}

void	fdf_setdots(t_glb *glb, int x, int y, int even)
{
	int	z;

	z = glb->mtx[y][2 * x];
	// printf("%d \t", z);
	glb->buf[2 * even] = x * glb->scale;
	glb->buf[2 * even + 1] = y * glb->scale;
	glb->buf[2 * even] = (x - y) * glb->scale * cos(0.9) + z;
	glb->buf[2 * even + 1] = (x + y) * glb->scale * sin(0.9) - z;
	glb->buf[2 * even] += glb->buf[8];
	glb->buf[2 * even + 1] += glb->buf[9];
	// if (z)
	// 	glb->buf[4 + even] = 0xff0080;
	// else
		glb->buf[4 + even] = glb->mtx[y][2 * x + 1];
}

void	fdf_draw(t_glb *glb)
{
	int	x;
	int	y;

	if (!glb)
		return ;
	x = 0;
	while (x < glb->x - 1)
	{
		y = 0;
		while (y < glb->y - 1)
		{
			fdf_setdots(glb, x, y, 0);
			// if (x < glb->x - 1)
			{
				fdf_setdots(glb, x + 1, y, 1);
				fdf_bresenham(glb);
			}
			// if (x < glb->y - 1)
			{
				fdf_setdots(glb, x, y + 1, 1);
				fdf_bresenham(glb);
			}
			y++;
		}
		// ft_putnbr_fd(x, 1);
		// ft_putstr_fd("\t", 1);
		x++;
	}
	mlx_put_image_to_window(glb->mlx_ptr, glb->win_ptr, glb->img_ptr, 0, 0);
}

int	fdf_hook(int key, t_glb *glb)
{
	ft_putnbr_fd(key, 1);
	ft_putstr_fd("\t", 1);
	if (key == 124)
		glb->buf[8] += 10;
	else if (key == 123)
		glb->buf[8] -= 10;
	else if (key == 125)
		glb->buf[9] += 10;
	else if (key == 126)
		glb->buf[9] -= 10;
	else if (key == 78 && glb->scale > 2)
		glb->scale /= 2;
	else if (key == 69)
		glb->scale *= 2;
	else if (key == 53)
		exit (0);
	mlx_clear_window(glb->mlx_ptr, glb->win_ptr);
	mlx_destroy_image(glb->mlx_ptr, glb->img_ptr);
	glb->img_ptr = 0;
	glb->img_ptr = mlx_new_image(glb->mlx_ptr, FDF_WIDTH, FDF_HEIGHT);
	mlx_get_data_addr(glb->img_ptr, &glb->pixel_bits, &glb->line_bytes,
		&glb->endian);
	fdf_draw(glb);
	return (0);
}

int	main(int argc, char **argv)
{
	t_glb	*glb;

	glb = fdf_initializemtx(argc, argv);
	// fdf_putmtx(glb);
	fdf_initializemlx(glb);
	fdf_draw(glb);
	mlx_key_hook(glb->win_ptr, fdf_hook, glb);
	mlx_loop(glb->mlx_ptr);
}
