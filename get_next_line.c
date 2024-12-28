#include "get_next_line.h"
#include <fcntl.h>

char	*_realloc(char *line, int size)
{
	char	*new_line;
	int		i;
	new_line = (char *)malloc(sizeof(char) * size);
	if (!new_line)
		return (NULL);
	i = 0;
	while (line[i])
	{
		new_line[i] = line[i];
		i++;
	}
	free(line);
	return (new_line);
}

char	*get_next_line(int fd)
{
	char	*line;
	int		index;
	int		count;

	if (fd < 0)
		return (NULL);
	index = 0;
	count = BUFFER_SIZE;
	line = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	if (!line)
		return (NULL);
	while (read(fd, line + index, 1) > 0)
	{
		if (line[index] == '\n')
			return (line);
		if (index >= count)
		{
			count *= 2;
			line = _realloc(line, count);
		}
		index++;
	}
	return (line);
}
