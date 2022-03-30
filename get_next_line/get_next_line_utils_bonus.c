/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoetess <bpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 17:19:48 by bpoetess          #+#    #+#             */
/*   Updated: 2022/02/22 19:11:52 by bpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include "../libft/libft.h"

char	*ft_gnl_buffer(ssize_t *readc, int fd, char **str_p)
{
	char	bf[BUFFER_SIZE + 1];
	char	*temp;
	size_t	i;

	*readc = read (fd, bf, BUFFER_SIZE);
	bf[*readc] = '\0';
	temp = *str_p;
	*str_p = ft_strjoin(temp, bf);
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
