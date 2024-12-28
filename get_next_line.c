#include "get_next_line.h"
#include <fcntl.h>
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
			line = ft_realloc(line, count);
		}
		index++;
	}
	return (line);
}
