#include "get_next_line.h"
#include <stdio.h>

size_t	ft_strlen(char *line)
{
	int	i;

	i = 0;
	if (line == NULL)
		return (0);
	while (line[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int	count;

	count = 0;
	if (!s)
		return (NULL);
	while (s[count])
	{
		if (s[count] == (unsigned char)c)
			return ((char *)(s + count));
		count++;
	}
	if ((unsigned char)c == 0)
		return ((char *)(s + count));
	return (NULL);
}

char	*extend_line(char *line, char *buffer)
{
	int	line_len;
	int	count;
	char	*new_line = NULL;
	if (!buffer)
		return (line);
	count = 0;
	while (buffer[count] && buffer[count] != '\n')
		count++;
	line_len = ft_strlen(line);
	new_line = calloc(line_len + count + 2, sizeof(char));
	count = 0;
	if (line)
	{
		while (line[count])
		{
			new_line[count] = line[count];
			count++;
		}
	}
	int	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		new_line[count] = buffer[i];
		i++;
		count++;
	}
	if (buffer[i] == '\n')
		new_line[count] = '\n';
	free(line);
	return (new_line);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char	*line = NULL;
	int	line_read;

	if (!buffer)
	{
		buffer = calloc(BUFFER_SIZE + 1, sizeof(char));
		if (!buffer)
			return (NULL);
	}
	while (strchr(buffer, '\n') == NULL)
	{
		line = extend_line(line, buffer);
		line_read = read(fd, buffer, BUFFER_SIZE);
		if (line_read <= 0)
			return (line);
	}
	line = extend_line(line, buffer);
	char *temp = strchr(buffer, '\n');
	if (temp + 1)
		temp = strdup(temp + 1);
	free(buffer);
	buffer = temp;
	return (line);
}
