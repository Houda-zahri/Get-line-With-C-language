/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzahri <hzahri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 16:48:58 by hzahri            #+#    #+#             */
/*   Updated: 2023/12/28 15:48:36 by hzahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>
#include <sys/fcntl.h>

char	*feedthefish(int fd, char *fish)
{
	char	*buffer;
	ssize_t	ret;

	buffer = malloc((size_t)BUFFER_SIZE + 1);
	if (!buffer)
		return (free(fish), buffer);
	(1) && (ret = 1, *buffer = 0);
	while (ret && !find_nl(buffer))
	{
		ret = read(fd, buffer, (size_t)BUFFER_SIZE);
		if (ret < 0)
			return (free(fish), free(buffer), NULL);
		buffer[ret] = 0;
		fish = ft_strjoin(fish, buffer);
		if (!*fish)
			return (free(fish), free(buffer), NULL);
	}
	return (free(buffer), fish);
}

char	*slice_the_line(char **fish)
{
	int		len;
	char	*line;
	char	*save;

	len = 0;
	save = *fish;
	while (save[len] && save[len] != '\n')
		len++;
	line = ft_substr(*fish, 0, len + 1);
	(save[len] == '\n') && (len++);
	*fish = ft_substr(save, len, ft_strlen(save + len));
	return (free(save), line);
}

char	*get_next_line(int fd)
{
	static char	*fish[OPEN_MAX];
	char		*line;

	if (fd > OPEN_MAX)
		return (NULL);
	fish[fd] = feedthefish(fd, fish[fd]);
	if (!fish[fd])
		return (fish[fd]);
	line = slice_the_line(&fish[fd]);
	return (line);
}
