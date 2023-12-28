/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzahri <hzahri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 16:48:58 by hzahri            #+#    #+#             */
/*   Updated: 2023/12/27 14:37:36 by hzahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char	*slice_the_fish(char **fish)
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
	static char	*fish;
	char		*line;

	fish = feedthefish(fd, fish);
	if (!fish)
		return (fish);
	line = slice_the_fish(&fish);
	return (line);
}

// int main ()
// {
// 	int fd1 = open("txt", O_RDONLY);
// 	char *line  = get_next_line(fd1);
// 	printf("%s", line);
// 	// int fd2 = open("txt2", O_RDONLY);
// 	// line  = get_next_line(fd2);
// 	// printf("%s", line);
// 	// int fd3 = open("txt3", O_RDONLY);
// 	// line  = get_next_line(fd3);
// 	// printf("%s---", line);
// }
