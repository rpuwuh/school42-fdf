/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoetess <bpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 05:27:05 by bpoetess          #+#    #+#             */
/*   Updated: 2022/04/03 05:33:37 by bpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_freelines(char ***l)
{
	int	i;
	int	j;

	if (!l || !*l || !**l)
		return ;
	i = 0;
	while (l[i])
	{
		j = 0;
		while (l[i][j])
			free (l[i][j++]);
		free (l[i][j]);
		free (l[i++]);
	}
	free (l[i]);
	free(l);
}

void	fdf_freemtx(int **mtx)
{
	int	i;

	if (!mtx || !*mtx)
		return ;
	i = 0;
	while (mtx[i])
		free (mtx[i++]);
	free (mtx[i]);
	free (mtx);
}

void	fdf_freeglb(t_glb *glb)
{
	if (!glb)
		return ;
	if (glb->mtx)
	{
		fdf_freemtx(glb->mtx);
		glb->mtx = 0;
	}
	if (glb->win_ptr)
	{
		mlx_destroy_window(glb->mlx_ptr, glb->win_ptr);
		glb->win_ptr = 0;
	}
	if (glb->img_ptr)
	{
		mlx_destroy_image(glb->mlx_ptr, glb->img_ptr);
		glb->img_ptr = 0;
	}
	if (glb->mlx_ptr)
	{
		free(glb->mlx_ptr);
		glb->mlx_ptr = 0;
	}
	free (glb);
}
