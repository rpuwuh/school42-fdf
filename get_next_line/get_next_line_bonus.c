/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoetess <bpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 17:19:45 by bpoetess          #+#    #+#             */
/*   Updated: 2022/01/02 19:43:45 by bpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line_old(char **tail, int fd)
{
	char		*s;
	ssize_t		readc;

	if (BUFFER_SIZE < 1 || fd < 0 || fd > MAX_BUFFER)
		return (0);
	if (tail && *tail)
		s = ft_strjoin(*tail, "");
	else
		s = ft_newstring();
	if (!s)
		return (0);
	readc = 1;
	while (readc > 0 && !ft_strchr(s, '\n'))
	{
		s = ft_gnl_buffer(&readc, fd, &s);
		if (!s)
			return (0);
	}
	s = ft_gnl_trim(readc, tail, &s);
	return (s);
}

void	ft_cleanfreestring(char **s)
{
	size_t	i;

	if (!s)
		return ;
	i = 0;
	while (*s && *s[i])
		*s[i] = '\0';
	if (*s)
		free(*s);
	*s = 0;
	return ;
}

char	*ft_gnl_trim(ssize_t readc, char **tail_p, char **str_p)
{
	char	*temp;
	size_t	len;

	if (!(readc || ft_strchr(*str_p, '\n')))
	{
		temp = 0;
		if (!(**str_p == '\0'))
			temp = ft_substr(*str_p, 0, ft_strchr(*str_p, '\0') - *str_p + 1);
		ft_cleanfreestring (tail_p);
		ft_cleanfreestring (str_p);
		return (temp);
	}
	if (readc == -1)
	{
		ft_cleanfreestring (str_p);
		return (0);
	}
	len = ft_strchr(*str_p, '\n') - *str_p;
	temp = ft_substr(*str_p, 0, len + 1);
	ft_cleanfreestring (tail_p);
	*tail_p = ft_substr (*str_p, len + 1, BUFFER_SIZE + 1);
	ft_cleanfreestring (str_p);
	return (temp);
}

char	*ft_newstring(void)
{
	char	*temp;
	size_t	i;

	temp = (char *) malloc ((sizeof (char)) * (BUFFER_SIZE + 1));
	if (!temp)
		return (0);
	i = 0;
	while (i < BUFFER_SIZE + 1)
		temp [i++] = '\0';
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*tails[MAX_BUFFER];
	char		*s;

	s = get_next_line_old(&(tails[fd]), fd);
	return (s);
}
