/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoetess <bpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 17:19:48 by bpoetess          #+#    #+#             */
/*   Updated: 2022/04/09 20:11:44 by bpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	gnl_strlen(const char	*s)
{
	size_t	i;

	if (!s || !*s)
		return (0);
	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

char	*gnl_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s [i])
	{
		if (s[i] == (unsigned char) c)
			return ((char *)(s + i));
		i++;
	}
	if (s[i] == (unsigned char) c)
		return ((char *)(s + i));
	return (0);
}

char	*gnl_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	i;
	size_t	t;

	res = (char *) malloc (gnl_strlen (s1) + gnl_strlen (s2) + 1);
	if (res == 0)
		return (res);
	i = 0;
	while (s1 [i])
	{
		res [i] = s1 [i];
		i++;
	}
	i = 0;
	t = gnl_strlen(s1);
	while (s2 [i])
	{
		res [t + i] = s2 [i];
		i++;
	}
	res [gnl_strlen (s1) + gnl_strlen (s2)] = '\0';
	return (res);
}

char	*ft_gnl_buffer(ssize_t *readc, int fd, char **str_p)
{
	char	bf[BUFFER_SIZE + 1];
	char	*temp;
	size_t	i;

	*readc = read (fd, bf, BUFFER_SIZE);
	bf[*readc] = '\0';
	temp = *str_p;
	*str_p = gnl_strjoin(temp, bf);
	if (!*str_p)
	{
		i = 0;
		while (temp[i])
			temp[i++] = '\0';
		free(temp);
		return (0);
	}
	i = 0;
	while (temp[i])
		temp[i++] = '\0';
	free(temp);
	return (*str_p);
}

char	*gnl_substr(char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*res;

	if (start >= gnl_strlen(s))
	{
		res = (char *) malloc (1);
		res[0] = '\0';
		return (res);
	}
	if (len > gnl_strlen(s + start))
		len = gnl_strlen(s + start);
	res = (char *) malloc (len + 1);
	if (res == 0)
		return (0);
	i = 0;
	while (i < len + 1)
		res[i++] = '\0';
	i = 0;
	while (i < len && s[start + i])
	{
		res[i] = s[start + i];
		i++;
	}
	res [len] = '\0';
	return (res);
}
