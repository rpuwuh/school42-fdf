/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_mallocandset.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoetess <bpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 05:24:29 by bpoetess          #+#    #+#             */
/*   Updated: 2022/04/13 20:11:19 by bpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	fdf_set_glb_const(t_glb *glb)
{
	if (!glb)
		return ;
	glb->mlx_ptr = 0;
	glb->win_ptr = 0;
	glb->img_ptr = 0;
	glb->scale = FDF_WIDTH / (1.5 * glb->x);
	if (!glb->scale)
		glb->scale = 2;
	glb->angles[0] = -M_PI / 5;
	glb->buf[8] = 20;
	glb->buf[9] = 360;
	glb->angles[1] = 1;
	glb->angles[2] = 0;
	glb->angles[3] = FDF_ANGLE;
	return ;
}

t_glb	*fdf_setglb(char ***lines)
{
	t_glb	*glb;
	int		i;

	glb = (t_glb *) malloc (sizeof(t_glb));
	if (!glb)
		return (0);
	if (!lines || !*lines || !**lines)
		return (glb);
	i = 0;
	while (lines[i])
		i++;
	glb->y = i;
	i = 0;
	while (lines[0][i])
		i++;
	glb->x = i;
	i = 0;
	while (i < 10)
		glb->buf [i++] = 0;
	fdf_set_glb_const(glb);
	return (glb);
}

static char	*fdf_safestr(char ***s, int i, int j)
{
	int	i1;
	int	j1;

	if (!s || !*s || !**s)
		return (0);
	i1 = 0;
	j1 = 0;
	while (s[i1] && i1 < i)
		i1++;
	if (!s[i1])
		return (0);
	while (s[i1][j1] && j1 < j)
		j1++;
	if (!s[i1][j1])
		return (0);
	return (s[i][j]);
}

void	fdf_setmtx(t_glb *glb, char	***lines)
{
	int	i;
	int	j;

	i = 0;
	while (i < glb->y)
	{
		j = 0;
		while (j < glb->x)
		{
			glb->mtx[i][2 * j] = ft_atoi(fdf_safestr(lines, i, j));
			if (fdf_safestr(lines, i, j) && ft_strchr(lines[i][j], ','))
				glb->mtx[i][2 * j + 1] = fdf_atoi_hex(ft_strchr
						(fdf_safestr(lines, i, j), 44) + 1);
			else
				glb->mtx[i][2 * j + 1] = 0xffffff;
			j++;
		}
		i++;
	}
	fdf_freelines(lines);
}

t_glb	*fdf_initializemtx(int argc, char **argv)
{
	char	***lines;
	t_glb	*glb;

	fdf_checkfile(argc, argv[1]);
	lines = fdf_secondsplit(argv[1]);
	glb = fdf_setglb(lines);
	if (!glb)
	{
		ft_putstr_fd("Memory allocation error\n", 2);
		fdf_freelines(lines);
		exit(1);
	}
	glb->mtx = fdf_mallocmtx(glb);
	if (!glb->mtx)
	{
		fdf_freeglb(glb);
		ft_putstr_fd("Memory allocation error\n", 2);
		exit(1);
	}
	fdf_setmtx (glb, lines);
	return (glb);
}
