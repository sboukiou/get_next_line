/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboukiou <sboukiou@1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 00:35:04 by sboukiou          #+#    #+#             */
/*   Updated: 2025/01/08 00:35:07 by sboukiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*fill_buffer(char *buffer, int fd)
{
	size_t	buffer_len;
	ssize_t	lines_read;

	buffer_len = ft_strlen(buffer, '\0');
	while (ft_strchr(buffer, NEWL) == NULL)
	{
		buffer = ft_realloc(buffer, BUFFER_SIZE + buffer_len + 1);
		if (!buffer)
			return (NULL);
		lines_read = read(fd, buffer + buffer_len, BUFFER_SIZE);
		if (lines_read >= 0)
			buffer[lines_read + buffer_len] = '\0';
		else
			buffer[buffer_len] = '\0';
		if (lines_read < 1)
			return (buffer);
		buffer_len += lines_read;
	}
	return (buffer);
}

char	*extract_line(char *buffer)
{
	char	*line;
	int		line_len;

	if (!buffer || !ft_strlen(buffer, '\0'))
		return (NULL);
	line_len = ft_strlen(buffer, '\n');
	line = (char *)malloc((size_t)(sizeof(char) * (line_len + 1)));
	if (!line)
		return (NULL);
	ft_strlcpy(line, buffer, line_len + 1);
	return (line);
}

char	*reset_buffer(char *buffer)
{
	char	*temp;
	char	*new_buffer;
	int		temp_len;

	temp = ft_strchr(buffer, NEWL);
	if (temp && temp[1])
	{
		temp_len = ft_strlen(temp + 1, '\0');
		new_buffer = (char *)malloc((size_t)(sizeof(char) * (temp_len + 1)));
		if (!new_buffer)
			return (free(buffer), buffer = NULL, NULL);
		ft_strlcpy(new_buffer, temp + 1, temp_len + 1);
		free(buffer);
		buffer = NULL;
		return (new_buffer);
	}
	free(buffer);
	buffer = NULL;
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = fill_buffer(buffer, fd);
	if (!buffer || !ft_strlen(buffer, '\0'))
		return (free(buffer), buffer = NULL, NULL);
	line = extract_line(buffer);
	if (!line)
		return (free(buffer), buffer = NULL, NULL);
	buffer = reset_buffer(buffer);
	return (line);
}
