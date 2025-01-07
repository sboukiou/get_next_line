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
			buffer[buffer_len + lines_read] = '\0';
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
	int	line_len;

	if (!buffer || !ft_strlen(buffer, '\0'))
		return (free(buffer), NULL);
	line_len = ft_strlen(buffer, '\n');
	line = (char *)malloc((size_t)(sizeof(char) * (line_len + 1)));
	if (!line)
		return (free(buffer), NULL);
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
			return (free(buffer), NULL);
		ft_strlcpy(new_buffer, temp + 1, temp_len + 1);
		free(buffer);
		return (new_buffer);
	}
	free(buffer);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	buffer = fill_buffer(buffer, fd);
	line = extract_line(buffer);
	buffer = reset_buffer(buffer);
	return (line);
}
