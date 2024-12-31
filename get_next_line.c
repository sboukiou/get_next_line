#include "get_next_line.h"
#include <stdio.h>

char	*extend_line(char *line, char *buffer)
{
	char	*new_line;
	int	idx;

	if (!buffer)
		return (line);
	idx = 0;
	while (buffer[idx] && buffer[idx] != '\n')
		idx++;
	new_line = (char *)calloc(ft_strlen(line) + idx + 2, sizeof(char));
	if (!new_line)
		return (NULL);
	if (line)
		strcpy(new_line, line);
	ft_strlcat(new_line, buffer, ft_strlen(new_line) + idx + 2);
	free(line);
	return (new_line);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	int			line_read;
	char	*temp;
	char	*new_buffer;

	if (BUFFER_SIZE < 0 || fd < 0)
		return (NULL);
	if (read(fd, 0, 0) <= 0)
		return (NULL);
	line = NULL;
	if (!buffer)
	{
		buffer = (char *)calloc(BUFFER_SIZE + 1, sizeof(char));
		if (!buffer)
			return (NULL);
		line_read = read(fd, buffer, BUFFER_SIZE);
		if (line_read < 1)
		{
			free(buffer);
			buffer = NULL;
			return (NULL);
		}
		buffer[line_read] = '\0';
	}
	while (ft_strchr(buffer, '\n') == NULL)
	{
		line = extend_line(line, buffer);
		line_read = read(fd, buffer, BUFFER_SIZE);
		if (line_read <= 0)
		{
			free(buffer);
			buffer = NULL;
			return (line);
		}
		buffer[line_read] = '\0';
	}
	line = extend_line(line, buffer);
	temp = ft_strchr(buffer, '\n');
	if (temp)
	{
		new_buffer =  (char *)calloc(BUFFER_SIZE + 1, sizeof(char));
		strcpy(new_buffer, temp + 1);
		free(buffer);
		buffer = new_buffer;
	}
	return (line);

}

