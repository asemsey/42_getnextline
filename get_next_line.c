/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemsey <asemsey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 14:12:46 by asemsey           #+#    #+#             */
/*   Updated: 2023/10/30 09:29:45 by asemsey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_str(int fd, char *next);
char	*copy_to_next(char *line);

char	*get_next_line(int fd)
{
	static char	*next;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
	{
		free(next);
		next = NULL;
		return (NULL);
	}
	line = read_str(fd, next);
	if (!line)
	{
		free(next);
		next = NULL;
		return (NULL);
	}
	next = copy_to_next(line);
	if (!next)
	{
		free(line);
		return (NULL);
	}
	return (line);
}

char	*copy_to_next(char *line)
{
	int		nextlen;
	char	*next;
	int		i;

	if (!ft_strchr(line, '\n') && ft_strlen(line) > 0)
	{
		next = malloc(1);
		if (!next)
			return (NULL);
		*next = '\0';
		return (next);
	}
	nextlen = ft_strlen(ft_strchr(line, '\n'));
	next = ft_substr(ft_strchr(line, '\n'), 1, nextlen);
	if (!next)
		return (NULL);
	i = 0;
	while (line[i] != '\0' && line[i] != '\n')
		i++;
	if (line[i] == '\n')
		i++;
	line[i] = '\0';
	return (next);
}

char	*move_next(char *next)
{
	char	*line;

	line = NULL;
	if (!next)
	{
		line = malloc(1);
		if (!line)
			return (NULL);
		*line = 0;
		return (line);
	}
	line = ft_strjoin(line, next);
	free(next);
	next = NULL;
	if (!line)
		return (NULL);
	return (line);
}

char	*read_str(int fd, char *next)
{
	char	*line;
	char	*buffer;
	int		bytes_read;

	line = move_next(next);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!line || !buffer)
		return (free(line), free(buffer), NULL);
	while (!ft_strchr(line, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			break ;
		buffer[bytes_read] = '\0';
		line = ft_strjoin(line, buffer);
		if (!line)
			break ;
	}
	free(buffer);
	if (bytes_read < 0)
	{
		free(line);
		return (NULL);
	}
	return (line);
}
