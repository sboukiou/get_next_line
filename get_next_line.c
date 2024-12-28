#include "get_next_line.h"

char	*strdup_newline(char *buffer)
{
	int	index;
	char	*line;

	index = 0;
	while (buffer[index] && buffer[index] != '\n')
		index++;
	line = calloc(index, sizeof(char));
	index = 0;
	while (buffer[index] && buffer[index] != '\n')
	{
		line[index] = buffer[index];
		index++;
	}
	return (line);
	
}

char *fetch_line(char *buffer, char *line)
{
	int	line_len;
	int	index;
	if (!buffer)
		return (NULL);
	index = 0;
	if (!line)
	{
		line = strdup_newline(buffer);
		return (line);
	}
	line_len = strlen(line);
	line = realloc(line, line_len + BUFFER_SIZE + 1);
	strlcat(line, buffer, line_len + BUFFER_SIZE + 1);
	return (line);
}


char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	char		*temp;
	int			count;
	line = NULL;
	if (!buffer)
	{
		buffer = calloc(BUFFER_SIZE, sizeof(char));
		count = read(fd, buffer, BUFFER_SIZE);
		if (count < 0)
			return (line);
	}
	while (!strchr(buffer, '\n'))
	{
		line = fetch_line(buffer, line);
		count = read(fd, buffer, BUFFER_SIZE);
		if (count < 0)
			return (line);
	}
	line = fetch_line(buffer, line);
	temp = strdup(strchr(buffer, '\n') + 1);
	free(buffer);
	buffer = temp;
	return (line);
}
