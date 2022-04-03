/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoetess <bpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 01:10:46 by bpoetess          #+#    #+#             */
/*   Updated: 2022/04/03 05:34:47 by bpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include "libft/libft.h"
# include "get_next_line/get_next_line_bonus.h"
# include "minilibx/mlx.h"

typedef struct s_glb
{
	int		x;
	int		y;
	int		**mtx;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
}	t_glb;

int		fdf_atoi_hex(const char *s);

void	fdf_checkfile(int c, char *file);
char	*ft_stradd(char	**dest, char *src);
char	**fdf_mallocfile(char *file);
char	***fdf_secondsplit(char *file);

t_glb	*fdf_setglb(char ***lines);
int		**fdf_mallocmtx(t_glb	*glb);
void	fdf_setmtx(t_glb *glb, char	***lines);
t_glb	*fdf_initializemtx(int argc, char **argv);

void	fdf_freelines(char ***l);
void	fdf_freemtx(int **mtx);
void	fdf_freeglb(t_glb *glb);

#endif