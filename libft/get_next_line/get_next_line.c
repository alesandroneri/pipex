/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneri-da <aneri-da@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:31:54 by aneri-da          #+#    #+#             */
/*   Updated: 2025/01/22 14:09:31 by aneri-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_and_join(int fd, char **reminder, char *buffer)
{
	int		bytes_read;
	char	*temp;

	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read < 0)
	{
		free(*reminder);
		*reminder = NULL;
		return (NULL);
	}
	if (bytes_read == 0)
		return (NULL);
	buffer[bytes_read] = '\0';
	temp = *reminder;
	*reminder = ft_gnljoin(*reminder, buffer);
	free(temp);
	if (*reminder == NULL)
		return (NULL);
	return (*reminder);
}

char	*check_newline(char **reminder, char **line)
{
	char	*newline;
	char	*temp;
	char	*temp_line;

	newline = ft_strchr(*reminder, '\n');
	if (ft_strchr(*reminder, '\n'))
	{
		*newline = '\0';
		*line = ft_gnljoin(*reminder, "");
		temp = *reminder;
		*reminder = ft_gnljoin(newline + 1, "");
		free(temp);
		if (!*reminder)
			return (free(*line), NULL);
		temp_line = *line;
		*line = ft_gnljoin(temp_line, "\n");
		free(temp_line);
	}
	else if (*reminder && **reminder)
	{
		*line = ft_gnljoin(*reminder, "");
		free(*reminder);
		*reminder = NULL;
	}
	return (*line);
}

char	*checking_malloc_read_fd(int fd)
{
	char	*checked_buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	checked_buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!checked_buffer)
		return (NULL);
	return (checked_buffer);
}

char	*get_next_line(int fd)
{
	static char	*reminder = NULL;
	char		*buffer;
	char		*line;
	char		*newline;

	buffer = checking_malloc_read_fd(fd);
	if (!buffer)
		return (NULL);
	newline = ft_strchr(reminder, '\n');
	while (!newline)
	{
		if (!read_and_join(fd, &reminder, buffer))
		{
			if (!reminder || !*reminder)
			{
				free(reminder);
				reminder = NULL;
				return (free(buffer), NULL);
			}
			break ;
		}
		newline = ft_strchr(reminder, '\n');
	}
	free(buffer);
	return (check_newline(&reminder, &line));
}
