/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_key_hook.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoetess <bpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 20:42:32 by bpoetess          #+#    #+#             */
/*   Updated: 2022/05/05 18:17:41 by bpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	fdf_hook_base(int key, t_glb *glb)
{
	glb->angles[0] = 0;
	glb->angles[1] = 0;
	glb->angles[2] = 0;
	glb->angles[3] = 0;
	glb->buf[8] = 20;
	glb->buf[9] = 20;
	if (key == 19 || key == 20)
	{
		glb->angles[1] = M_PI / 2;
		glb->buf[9] = FDF_HEIGHT - 20;
	}
	if (key == 20)
		glb->angles[0] = -M_PI / 2;
}

static void	fdf_redraw(t_glb *glb)
{
	mlx_clear_window(glb->mlx_ptr, glb->win_ptr);
	mlx_destroy_image(glb->mlx_ptr, glb->img_ptr);
	glb->img_ptr = 0;
	glb->img_ptr = mlx_new_image(glb->mlx_ptr, FDF_WIDTH, FDF_HEIGHT);
	mlx_get_data_addr(glb->img_ptr, &glb->pixel_bits, &glb->line_bytes,
		&glb->endian);
	fdf_draw(glb);
}

static void	fdf_hook_angles(int key, t_glb *glb)
{
	if (key == 12)
		glb->angles[0] -= 0.05;
	else if (key == 14)
		glb->angles[0] += 0.05;
	else if (key == 13)
		glb->angles[0] = 0;
	else if (key == 0)
		glb->angles[1] -= 0.05;
	else if (key == 2)
		glb->angles[1] += 0.05;
	else if (key == 1)
		glb->angles[1] = 0;
	else if (key == 6)
		glb->angles[2] -= 0.05;
	else if (key == 8)
		glb->angles[2] += 0.05;
	else if (key == 7)
		glb->angles[2] = 0;
	else if (key == 30)
		glb->angles[3] -= 0.05;
	else if (key == 33)
		glb->angles[3] += 0.05;
}

int	fdf_hook(int key, t_glb *glb)
{
	if (key == 124 && glb->buf[8] < glb->x * 3 + FDF_WIDTH)
		glb->buf[8] += glb->scale * 3;
	else if (key == 123)
		glb->buf[8] -= glb->scale * 3;
	else if (key == 125)
		glb->buf[9] += glb->scale * 3;
	else if (key == 126)
		glb->buf[9] -= glb->scale * 3;
	else if (key == 12 || key == 14 || key == 0 || key == 2 || key == 6
		|| key == 8 || key == 30 || key == 33 || key == 13 || key == 1
		|| key == 7)
		fdf_hook_angles(key, glb);
	else if ((key == 78 || key == 27) && glb->scale > 2)
		glb->scale /= 2;
	else if (key == 69 || key == 24)
		glb->scale *= 2;
	else if (key == 82 || key == 29 || key == 18 || key == 19 || key == 20)
		fdf_hook_base(key, glb);
	else if (key == 53)
		exit (0);
	else
		return (0);
	fdf_redraw(glb);
	return (0);
}
