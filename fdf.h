/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoetess <bpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 01:10:46 by bpoetess          #+#    #+#             */
/*   Updated: 2022/04/04 20:44:57 by bpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define FDF_HEIGHT 720
# define FDF_WIDTH 1280

# include <fcntl.h>
# include <math.h>

# include "libft/libft.h"
# include "get_next_line/get_next_line_bonus.h"
# include "minilibx/mlx.h"

typedef struct s_glb
{
	int		x;
	int		y;
	int		**mtx;
	int		buf[8];
	int		scale;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	int		pixel_bits;
	int		line_bytes;
	int		endian;
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

void	fdf_initializemlx(t_glb *glb);
void	fdf_put_pixel_img(t_glb *glb, int x, int y, int c);

void	fdf_bresenham(t_glb *glb);

#endif