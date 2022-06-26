/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jala <sel-jala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 22:16:31 by sel-jala          #+#    #+#             */
/*   Updated: 2022/06/26 21:06:08 by sel-jala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free_gnl(char	*res, char	*buffer)
{
	char	*temp;

	temp = ft_strjoin(res, buffer);
	return (temp);
}

char	*readnext(char	*res)
{
	int		i;
	int		j;
	char	*next;

	i = 0;
	j = 0;
	while (res[i] && res[i] != '\n')
		i++;
	if (!res[i])
	{
		free(res);
		return (NULL);
	}
	next = ft_calloc(ft_strlen(res) - i + 1, sizeof(char));
	i++;
	while (res[i])
	{
		next[j++] = res[i++];
	}
	next[j] = '\0';
	free(res);
	return (next);
}

char	*readline(char	*res)
{
	int		i;
	char	*line;

	i = 0;
	if (!res[i])
		return (NULL);
	while (res[i] && res[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (res[i] && res[i] != '\n')
	{
		line[i] = res[i];
		i++;
	}
	if (res[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*readfile(int fd, char	*res)
{
	int		byteread;
	char	*buffer;

	byteread = 1;
	if (!res)
		res = ft_calloc(1, 1);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
	{
		free(buffer);
		return (NULL);
	}
	while (!ft_strchr(buffer, '\n') && byteread > 0)
	{
		byteread = read(fd, buffer, BUFFER_SIZE);
		if (byteread == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[byteread] = '\0';
		res = ft_free_gnl(res, buffer);
	}
	free(buffer);
	return (res);
}

char	*get_next_line(int fd)
{
	static char		*res;
	char			*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (0);
	res = readfile(fd, res);
	if (!res)
		return (NULL);
	line = readline(res);
	res = readnext(res);
	return (line);
}
