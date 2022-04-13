/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoetess <bpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 17:38:18 by bpoetess          #+#    #+#             */
/*   Updated: 2022/04/13 18:41:40 by bpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	fdf_setdots(t_glb *glb, int x, int y, int even)
{
	int	z;

	z = glb->mtx[y][2 * x];
	glb->buf[2 * even] = (x * (cos(glb->angles[0]) * cos(glb->angles[2])
				- cos(glb->angles[1]) * sin(glb->angles[0])
				* sin(glb->angles[2]))
			+ y * (-cos(glb->angles[2]) * sin(glb->angles[0])
				- cos(glb->angles[0]) * cos(glb->angles[1])
				* sin(glb->angles[2])) + 0.15
			* z * (sin(glb->angles[1]) * sin(glb->angles[2]))) * glb->scale;
	glb->buf[2 * even + 1] = (x * (cos(glb->angles[1]) * cos(glb->angles[2])
				* sin(glb->angles[0]) + cos(glb->angles[0])
				* sin(glb->angles[2])) + y * (cos(glb->angles[0])
				* cos(glb->angles[1]) * cos(glb->angles[2])
				- sin(glb->angles[0]) * sin(glb->angles[2])) + 0.15 * z
			* (-cos(glb->angles[2]) * sin (glb->angles[1]))) * glb->scale;
	glb->buf[2 * even] += glb->buf[8];
	glb->buf[2 * even + 1] += glb->buf[9];
	glb->buf[4 + even] = glb->mtx[y][2 * x + 1];
}

static void	fdf_draw_set(t_glb *glb, int x, int y)
{
	fdf_setdots(glb, x, y, 0);
	if (x < glb->x - 1)
	{
		fdf_setdots(glb, x + 1, y, 1);
		fdf_bresenham(glb);
	}
	if (y < glb->y - 1)
	{
		fdf_setdots(glb, x, y + 1, 1);
		fdf_bresenham(glb);
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
			fdf_draw_set(glb, x, y);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(glb->mlx_ptr, glb->win_ptr, glb->img_ptr, 0, 0);
}
