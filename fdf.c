/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoetess <bpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 01:13:08 by bpoetess          #+#    #+#             */
/*   Updated: 2022/05/05 18:34:30 by bpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	fdf_exit(int exit_code)
{
	exit(exit_code);
}

int	main(int argc, char **argv)
{
	t_glb	*glb;

	glb = fdf_initializemtx(argc, argv);
	fdf_initializemlx(glb);
	fdf_draw(glb);
	mlx_key_hook(glb->win_ptr, fdf_hook, glb);
	mlx_hook(glb->win_ptr, 17, 0, fdf_exit, 0);
	mlx_loop(glb->mlx_ptr);
}
