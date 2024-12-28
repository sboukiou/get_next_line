#include "get_next_line.h"

char	*strdup_newline(char *buffer)
{
	int	index;
	char	*line;

	index = 0;
	while (index < BUFFER_SIZE && buffer[index] != '\n')
		index++;
	line = calloc(index, sizeof(char));
	index = 0;
	while (index < BUFFER_SIZE && buffer[index] != '\n')
	{
		line[index] = buffer[index];
		index++;
	}
	line[index] = '\0';
	return (line);
	
}

char *fetch_line(char *buffer, char *line)
{
	int	line_len;
	int count;
	if (!buffer)
		return (NULL);
	if (!line)
	{
		line = strdup_newline(buffer);
		return (line);
	}
	line_len = strlen(line);
	count = 0;
	while (buffer[count] && buffer[count] != '\n')
		count++;
	line = realloc(line, line_len + count + 2);
	strlcat(line, buffer, line_len + count + 2);
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
		/*BUFFER_SIZE = 12*/
		buffer = calloc(BUFFER_SIZE, sizeof(char));
		count = read(fd, buffer, BUFFER_SIZE);
		if (count < 0)
			return (line);
	}
	while (!strchr(buffer, '\n'))
	{
		line = fetch_line(buffer, line);
		count = read(fd, buffer, BUFFER_SIZE);
		if (count <= 0)
			return (line);
	}
	line = fetch_line(buffer, line);
	if (strchr(buffer, '\n')[1])
		temp = strdup(strchr(buffer, '\n') + 1);
	else
		temp = NULL;
	free(buffer);
	buffer = temp;
	return (line);
}
