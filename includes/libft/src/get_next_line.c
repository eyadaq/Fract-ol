/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaqrabaw <eaqrabaw@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 02:56:13 by eaqrabaw          #+#    #+#             */
/*   Updated: 2025/01/25 01:23:29 by eaqrabaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

char	*fill_line(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i] != '\0')
	{
		if (buffer[i] == '\n')
			return (ft_substr(buffer, 0, i + 1));
		i++;
	}
	return (ft_strdup(buffer));
}

char	*read_and_store(int fd, char **s)
{
	char	*buffer;
	char	*temp;
	int		bytesread;

	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (1)
	{
		bytesread = read(fd, buffer, BUFFER_SIZE);
		if (bytesread < 0)
			return (free(buffer), NULL);
		buffer[bytesread] = '\0';
		temp = *s;
		if (*s)
			*s = ft_strjoin(*s, buffer);
		else
			*s = ft_strdup(buffer);
		free(temp);
		if (!*s || ft_strchr(*s, '\n') || bytesread < BUFFER_SIZE)
			break ;
	}
	return (free(buffer), *s);
}

/**
 * Reads a line from a file descriptor and returns it.
 *
 * The function reads from a file descriptor until it encounters a newline
 * character or reaches the end of the file. It stores the remaining characters
 * in a static string for subsequent calls. The function returns the line read
 * or NULL if an error occurs or if the end of the file is reached.
 *
 * The function also handles the case where the file descriptor is invalid or
 * if the buffer size is less than or equal to 0.
 *
 * The function does not append a newline character to the end of the line.
 *
 * @param fd The file descriptor to read from.
 * @return The line read from the file descriptor or NULL if an error occurs.
 */
char	*get_next_line(int fd)
{
	static char	*s;
	char		*line;
	char		*temp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!read_and_store(fd, &s) || !s || *s == '\0')
	{
		free(s);
		s = NULL;
		return (NULL);
	}
	line = fill_line(s);
	temp = s;
	s = ft_substr(s, ft_strlen(line), ft_strlen(s) - ft_strlen(line));
	free(temp);
	if (!s)
		return (free(line), NULL);
	return (line);
}
