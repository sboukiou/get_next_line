#include "get_next_line.h"
#include <stdio.h>

char	*reset_buffer(char *buffer)
{
	char	*temp;
	char	*new_buffer;

	temp = ft_strchr(buffer, '\n');
	if (temp && temp[1])
	{
		new_buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		ft_strlcpy(new_buffer, temp + 1, ft_strlen(temp + 1));
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

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	if (!buffer)
	{
		buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		if (!buffer)
			return (NULL);
	}

	if (buffer && read(fd, buffer, 0) <= 0)
		return (free(buffer), NULL);
	line = NULL;
	while (!ft_strchr(buffer, '\n'))
	{
		line = extend_line(line, buffer);
		if (!line)
			return (free(buffer), NULL);
		if (read(fd, buffer, BUFFER_SIZE) <= 0)
		{
			free(buffer);
			buffer = NULL;
			return (line);
		}
	}
	line = extend_line(line, buffer);
	if (!line)
		return (free(buffer), NULL);
	buffer = reset_buffer(buffer);
	return (line);
}

