/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoetess <bpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 01:13:08 by bpoetess          #+#    #+#             */
/*   Updated: 2022/03/30 05:17:39 by bpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_checkfile(int c, char *file)
{
	char	*s;
	int		fd;

	if (c != 2)
	{
		ft_putstr_fd("Usage : ./fdf <filename>\n", 2);
		exit(1);
	}
	fd = open (file, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Cannot open the file\n", 2);
		exit(1);
	}
	s = get_next_line(fd);
	if (!s)
	{
		ft_putstr_fd("Empty file\n", 2);
		exit(1);
	}
	free(s);
	close(fd);
	return ;
}

char	*ft_stradd(char	**dest, char *src)
{
	char	*res;

	if (!dest)
		return (0);
	if (!src)
		return (*dest);
	if (!(*dest))
		return (ft_strdup(src));
	res = ft_strjoin(*dest, src);
	free(*dest);
	*dest = res;
	return (res);
}

char	**fdf_mallocfile(char *file)
{
	int		fd;
	char	**res;
	char	*s;
	char	*s2;

	fd = open (file, O_RDONLY);
	s = 0;
	s2 = get_next_line(fd);
	s = ft_stradd(&s, s2);
	while (s2)
	{
		free (s2);
		s2 = get_next_line(fd);
		s = ft_stradd(&s, s2);
	}
	close (fd);
	res = ft_split(s, '\n');
	free (s);
	return (res);
}

char	***fdf_secondsplit(char *file)
{
	char	***res;
	char	**lines;
	int		i;

	lines = fdf_mallocfile(file);
	if (!lines || !*lines)
		return (0);
	i = 0;
	while (lines[i])
		i++;
	res = (char ***) malloc(i + 1);
	if (!res)
		return (0);
	i = 0;
	while (lines[i])
	{
		res [i] = ft_split(lines[i], ' ');
		free (lines[i]);
		i++;
	}
	res [i] = 0;
	free (lines);
	return (res);
}

int	fdf_countptrs(void *ptrs)
{
	size_t	res;

	if (!ptrs)
		return (0);
	res = 0;
	while (((int *) ptrs)[res])
		res++;
	return ((int)res);
}

int	**fdf_getmatrix(char	***lines)
{
	int	**res;
	int	i;
	int	j;

	res = (int **) malloc (sizeof(int **) * (fdf_countptrs((void *)lines) + 1));
	if (!res)
		return (0);
	i = 0;
	while (lines[i])
	{
		res[i] = (int *)malloc(2 * sizeof(int *)
				* (fdf_countptrs(lines[i]) + 1));
		j = 0;
		while (lines[i][j])
		{
			res[i][2 * j] = ft_atoi(lines[i][j]);
			if (ft_strchr(lines[i][j], ','))
				res[i][2 * j + 1] = fdf_atoi_hex(ft_strchr(lines[i][j], 44) + 1);
			else
				res[i][2 * j + 1] = 0;
			j++;
		}
		res[i][j] = 0;
		i++;
	}
	res[i] = 0;
	return (res);
}

void	fdf_putmtx(int **mtx)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (mtx[i])
	{
		j = 0;
		while (mtx [i][j])
			ft_putnbr_fd(mtx[i][j++], 1);
		ft_putstr_fd("\n", 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int		fd;
	char	***lines;
	int		**matrix;

	(void) fd;
	fdf_checkfile(argc, argv[1]);
	lines = fdf_secondsplit(argv[1]);
	matrix = fdf_getmatrix (lines);
	fdf_putmtx(matrix);
}
