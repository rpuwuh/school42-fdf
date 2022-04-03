/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoetess <bpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 01:13:08 by bpoetess          #+#    #+#             */
/*   Updated: 2022/04/03 08:19:50 by bpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_putmtx(t_glb *glb)
{
	int	i;
	int	j;

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

void	fdf_initializemlx(t_glb *glb)
{
	if (!glb)
		return ;
	glb->mlx_ptr = mlx_init();
	glb->win_ptr = mlx_new_window(glb->mlx_ptr, FDF_HEIGHT, FDF_WIDTH, "fdf");
	mlx_clear_window(glb->mlx_ptr, glb->win_ptr);
	glb->img_ptr = mlx_new_image(glb->mlx_ptr, FDF_HEIGHT, FDF_WIDTH);
	mlx_get_data_addr(glb->img_ptr, &glb->pixel_bits, &glb->line_bytes,
		&glb->endian);
}

void	fdf_put_pixel_img(t_glb *glb, int x, int y, int c)
{
	int		pixel;
	char	*buffer;

	if (glb->pixel_bits != 32)
		c = mlx_get_color_value(glb->mlx_ptr, c);
	buffer = mlx_get_data_addr(glb->img_ptr, &glb->pixel_bits, &glb->line_bytes,
			&glb->endian);
	{
		pixel = (y * glb->line_bytes) + (x * 4);
		if (glb->endian == 1)
		{
			buffer[pixel + 0] = (c >> 24);
			buffer[pixel + 1] = (c >> 16) & 0xFF;
			buffer[pixel + 2] = (c >> 8) & 0xFF;
			buffer[pixel + 3] = (c) & 0xFF;
		}
		else if (!glb->endian)
		{
			buffer[pixel + 0] = (c) & 0xFF;
			buffer[pixel + 1] = (c >> 8) & 0xFF;
			buffer[pixel + 2] = (c >> 16) & 0xFF;
			buffer[pixel + 3] = (c >> 24);
		}
	}
}

void	fdf_bresenham(t_glb *glb, )

int	main(int argc, char **argv)
{
	t_glb	*glb;

	glb = fdf_initializemtx(argc, argv);
	fdf_initializemlx(glb);
	
	mlx_put_image_to_window(glb->mlx_ptr, glb->win_ptr, glb->img_ptr, 0, 0);
	mlx_loop(glb->mlx_ptr);
}
