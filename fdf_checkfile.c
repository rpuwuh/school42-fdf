/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_checkfile.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoetess <bpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 00:34:39 by bpoetess          #+#    #+#             */
/*   Updated: 2022/04/03 04:34:45 by bpoetess         ###   ########.fr       */
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
	res = (char ***) malloc(i * (sizeof(char **)) + 1);
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
