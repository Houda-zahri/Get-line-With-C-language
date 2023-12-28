/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzahri <hzahri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 03:40:12 by hzahri            #+#    #+#             */
/*   Updated: 2023/12/28 15:29:18 by hzahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	int		i;
	int		j;

	if (!s1)
		return (ft_strdup(s2));
	ptr = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!ptr)
		return (NULL);
	(1) && (i = 0, j = 0);
	while (s1[j])
		ptr[i++] = s1[j++];
	j = 0;
	while (s2[j])
		ptr[i++] = s2[j++];
	ptr[i] = '\0';
	return (free((void *)s1), ptr);
}

size_t	ft_strlen(const char *s)
{
	size_t	l;

	l = 0;
	while (s[l])
		l++;
	return (l);
}

char	*ft_strdup(const char *src)
{
	int		i;
	char	*mal;

	mal = (char *)malloc(1 + ft_strlen(src));
	if (!mal)
		return (NULL);
	i = 0;
	while (src[i])
	{
		mal[i] = src[i];
		i++;
	}
	mal[i] = '\0';
	return (mal);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	unsigned int	j;
	char			*ptr;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup("\0"));
	if (len > (ft_strlen(s) - start))
		len = (ft_strlen(s) - start);
	ptr = malloc(len + 1);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < start)
		i++;
	j = 0;
	while (i < (start + len) && s[i] != '\0')
		ptr[j++] = s[i++];
	ptr[j] = '\0';
	return (ptr);
}

bool	find_nl(const char *s)
{
	while (*s)
		if (*s++ == '\n')
			return (true);
	return (false);
}
