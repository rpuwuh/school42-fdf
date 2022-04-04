/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_mlx_funcs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoetess <bpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 20:23:49 by bpoetess          #+#    #+#             */
/*   Updated: 2022/04/04 20:24:01 by bpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_initializemlx(t_glb *glb)
{
	if (!glb)
		return ;
	glb->mlx_ptr = mlx_init();
	glb->win_ptr = mlx_new_window(glb->mlx_ptr, FDF_WIDTH, FDF_HEIGHT, "fdf");
	mlx_clear_window(glb->mlx_ptr, glb->win_ptr);
	glb->img_ptr = mlx_new_image(glb->mlx_ptr, FDF_WIDTH, FDF_HEIGHT);
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
