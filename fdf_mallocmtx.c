/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_mallocmtx.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoetess <bpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 21:26:58 by bpoetess          #+#    #+#             */
/*   Updated: 2022/04/09 21:27:09 by bpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	**fdf_mallocmtx(t_glb	*glb)
{
	int	i;
	int	j;

	if (!glb)
		return (0);
	glb->mtx = (int **) malloc (sizeof(int *) * (glb->y + 1));
	if (!glb->mtx)
		return (0);
	i = 0;
	while (i < glb->y)
	{
		glb->mtx[i++] = (int *) malloc (sizeof(int) * (glb->x * 2));
		j = 0;
		if (!glb->mtx[i - 1])
		{
			while (j < i)
				free(glb->mtx[j]);
			free(glb->mtx);
			return (0);
		}
		while (j < (glb->x * 2))
			glb->mtx[i - 1][j++] = 0;
	}
	glb->mtx[glb->y + 1] = 0;
	return (glb->mtx);
}
