#include "get_next_line.h"
#include <stdio.h>

char	*reset_buffer(char *buffer)
{
	char	*temp;
	char	*new_buffer;

	if (!ft_strlen(buffer))
		return (buffer);
	temp = ft_strchr(buffer, '\n');
	new_buffer = NULL;
	if (temp && temp[1] != '\0')
	{
		new_buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		ft_strlcpy(new_buffer, temp + 1, ft_strlen(temp + 1) + 1);
	}
	free(buffer);
	buffer = NULL;
	
	return (new_buffer);
}


char	*get_next_line(int file_d)
{
	char		*line;
	static char	*buffer;
	int			lines_read;

	if (!buffer)
	{
		buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		if (!buffer)
			return (NULL);
	}
	line = NULL;
	if (ft_strlen(buffer))
	{
		line = extend_line(line, buffer);
		buffer = reset_buffer(buffer);
		if (ft_strchr(line, '\n'))
			return (line);
	}
	lines_read = read(file_d, buffer, BUFFER_SIZE);
	if (lines_read < 1)
	{
		free(buffer);
		buffer = NULL;
		return (line);
	}
	while (ft_strchr(buffer, '\n') == NULL)
	{
		line = extend_line(line, buffer);
		buffer = reset_buffer(buffer);
		lines_read = read(file_d, buffer, BUFFER_SIZE);
		if (lines_read < 1)
		{
			free(buffer);
			buffer = NULL;
			return (line);
		}
	}
	line = extend_line(line, buffer);
	buffer = reset_buffer(buffer);
	return (line);
}
