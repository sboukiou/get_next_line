#include "get_next_line.h"
#include <stdio.h>

char	*reset_buffer(char *buffer)
{
	char	*temp;
	char	*new_buffer;

	temp = ft_strchr(buffer, '\n');
	new_buffer = NULL;
	if (temp && temp[1])
	{
		new_buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		ft_strlcpy(new_buffer, temp + 1, ft_strlen(temp + 1));
	}
	free(buffer);
	buffer = NULL;
	return (new_buffer);
}


char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	if (!buffer)
	{
		buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		if (!buffer)
			return (NULL);
	}

	if (buffer && read(fd, buffer, 0) < 0)
		return (free(buffer), buffer = NULL, NULL);
	line = NULL;
	while (!ft_strchr(buffer, '\n'))
	{
		line = extend_line(line, buffer);
		if (!line)
			return (free(buffer), buffer = NULL, NULL);
		if (!(*line))
			return (free(buffer), buffer = NULL, NULL);
		if (read(fd, buffer, BUFFER_SIZE) <= 0)
			return (free(buffer), buffer = NULL, line);
	}
	line = extend_line(line, buffer);
	if (!line)
		return (free(buffer), buffer = NULL, NULL);
	buffer = reset_buffer(buffer);
	return (line);
}

