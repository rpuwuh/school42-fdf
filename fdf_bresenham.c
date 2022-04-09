/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bresenham.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoetess <bpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 20:21:49 by bpoetess          #+#    #+#             */
/*   Updated: 2022/04/09 20:41:58 by bpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	fdf_maxabsint(int a1, int a2)
{
	if (abs (a1) > abs (a2))
		return (a1);
	else
		return (a2);
}

static int	fdf_hypot(int x, int y)
{
	return (sqrt (pow (x, 2) + pow (y, 2)));
}

static int	fdf_bres_color(t_glb *glb)
{
	double	diff;
	int		res;
	int		r;
	int		g;
	int		b;

	diff = fdf_hypot(glb->buf[0] - glb->buf[6], glb->buf[1] - glb->buf[7]);
	diff /= fdf_hypot(glb->buf[0] - glb->buf[2], glb->buf[1] - glb->buf[3]);
	r = ((glb->buf[4] >> 16) & 0xFF) + ((int)(diff * (((glb->buf[5] >> 16)
						& 0xFF) - ((glb->buf[4] >> 16) & 0xFF))));
	g = ((glb->buf[4] >> 8) & 0xFF) + ((int)(diff * (((glb->buf[5] >> 8)
						& 0xFF) - ((glb->buf[4] >> 8) & 0xFF))));
	b = ((glb->buf[4]) & 0xFF) + ((int)(diff * (double)(((glb->buf[5])
						& 0xFF) - ((glb->buf[4]) & 0xFF))));
	res = (r << 16) | (g << 8) | b;
	return (res);
}

void	fdf_bresenham(t_glb *glb)
{
	double	x_step;
	double	y_step;
	double	x;
	double	y;

	x = glb->buf[0];
	y = glb->buf[1];
	if (x > FDF_WIDTH)
		x = FDF_WIDTH;
	if (y > FDF_HEIGHT)
		y = FDF_HEIGHT;
	x_step = glb->buf[2] - x;
	y_step = glb->buf[3] - y;
	x_step /= abs(fdf_maxabsint (x - glb->buf[2], y_step));
	y_step /= abs(fdf_maxabsint (x - glb->buf[2], y_step));
	while (((int)(x - glb->buf[2]) || (int)(y - glb->buf[3]))
			&& x < FDF_WIDTH && y < FDF_HEIGHT)
	{
		glb->buf[6] = x;
		glb->buf[7] = y;
		if (x > 0 && y > 0)
			fdf_put_pixel_img(glb, x, y, fdf_bres_color(glb));
		x += x_step;
		y += y_step;
	}
}
